#include <iostream>
#include <vector>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  void addNodeAtEnd(ListNode **head_ref, int new_data)
  {
    ListNode *new_node = new ListNode();
    ListNode *last = *head_ref;
    new_node->val = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
      *head_ref = new_node;
      return;
    }
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = new_node;
    return;
  }
  ListNode *reverseList(ListNode *head)
  {
    std::vector<int> reverseLinkedList;
    while (head != NULL)
    {
      reverseLinkedList.push_back(head->val);
      head = head->next;
    }
    ListNode *result = NULL;
    for (size_t i = reverseLinkedList.size(); i > 0; i--)
    {
      addNodeAtEnd(&result, reverseLinkedList.at(i - 1));
    }
    return result;
  }
};

int main()
{
  Solution obj;
  ListNode *head_ = NULL;
  obj.addNodeAtEnd(&head_, 1);
  obj.addNodeAtEnd(&head_, 2);
  obj.addNodeAtEnd(&head_, 3);
  obj.addNodeAtEnd(&head_, 4);
  obj.addNodeAtEnd(&head_, 5);
  ListNode *result_ = obj.reverseList(head_);
  while (result_ != NULL)
  {
    std::cout << result_->val;
    result_ = result_->next;
  }
  std::cout << std::endl;
  return 0;
}