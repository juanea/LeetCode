#include <iostream>
// Definition for singly-linked list.
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

  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int count = 0;
    ListNode *countPtr = head;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    while (countPtr != NULL)
    {
      countPtr = countPtr->next;
      count++;
    }
    countPtr = dummy;
    for (size_t i = 0; i < count; i++)
    {
      if (count - n == i)
      {
        ListNode *removePtr = countPtr->next;
        if (removePtr->next == NULL)
        {
          countPtr->next = NULL;
        }
        else
        {
          countPtr->next = removePtr->next;
        }
        delete removePtr;
        break;
      }
      countPtr = countPtr->next;
    }
    return dummy->next;
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
  ListNode *result = obj.removeNthFromEnd(head, 2);
  while (result != NULL)
  {
    std::cout << result->val;
    result = result->next;
  }
  std::cout << std::endl;
  return 0;
}