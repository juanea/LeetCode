#include <iostream>

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
  ListNode *middleNode(ListNode *head)
  {
    ListNode *copy = head;
    int counter = 0;
    while (copy != NULL)
    {
      counter++;
      copy = copy->next;
    }
    counter = (counter + 2) / 2;
    for (int i = 0; i < counter - 1; i++)
    {
      head = head->next;
    }
    return head;
  }
};

int main()
{
  Solution obj;
  ListNode *head = NULL;
  obj.append(&head, 1);
  obj.append(&head, 2);
  obj.append(&head, 3);
  obj.append(&head, 4);
  obj.append(&head, 5);
  obj.append(&head, 6);

  ListNode *result = obj.middleNode(head);

  while (result != NULL)
  {
    std::cout << result->val;
    result = result->next;
  }

  std::cout << std::endl;
  return 0;
}