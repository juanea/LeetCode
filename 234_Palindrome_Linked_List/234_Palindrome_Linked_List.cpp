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
  void append(ListNode **head_ref, int new_data)
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

  bool isPalindrome(ListNode *head)
  {
    std::vector<int> linkedList;
    while (head)
    {
      linkedList.push_back(head->val);
      head = head->next;
    }
    for (int i = 0; i < linkedList.size(); i++)
    {
      if (linkedList.at(i) != linkedList.at(linkedList.size() - i - 1))
        return false;
    }
    return true;
  }
};

int main()
{
  Solution obj;
  ListNode *head = NULL;
  obj.append(&head, 1);
  obj.append(&head, 2);
  obj.append(&head, 2);
  obj.append(&head, 1);
  bool palindrome = obj.isPalindrome(head);
  std::cout << std::boolalpha << palindrome << std::endl;
}