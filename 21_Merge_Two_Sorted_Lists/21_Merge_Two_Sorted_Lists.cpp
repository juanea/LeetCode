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
  // Added this for local debugging
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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    struct ListNode *temp = new ListNode(0);
    struct ListNode *head = new ListNode(0);
    bool flag = false;
    if (list1 == NULL && list2 == NULL)
    {
      return NULL;
    }
    else if (list1 == NULL)
    {
      return list2;
    }
    else if (list2 == NULL)
    {
      return list1;
    }
    while (list1 != NULL && list2 != NULL)
    {
      if (list1->val < list2->val)
      {
        if (flag == false)
        {
          head = list1;
          temp = head;
        }
        else
        {
          temp->next = list1;
          temp = temp->next;
        }
        list1 = list1->next;
      }
      else
      {
        if (flag == false)
        {
          head = list2;
          temp = head;
        }
        else
        {
          temp->next = list2;
          temp = temp->next;
        }
        list2 = list2->next;
      }
      flag = true;
    }
    while (list1 != NULL)
    {
      temp->next = list1;
      temp = temp->next;
      list1 = list1->next;
    }
    while (list2 != NULL)
    {
      temp->next = list2;
      temp = temp->next;
      list2 = list2->next;
    }
    return head;
  }
};

int main()
{
  Solution obj;
  ListNode *head1 = NULL;
  ListNode *head2 = NULL;
  obj.append(&head1, 1);
  obj.append(&head1, 2);
  obj.append(&head1, 4);
  obj.append(&head2, 1);
  obj.append(&head2, 3);
  obj.append(&head2, 4);
  ListNode *result;
  result = obj.mergeTwoLists(head1, head2);
  while (result != NULL)
  {
    std::cout << result->val;
    result = result->next;
  }
  std::cout << std::endl;
  return 0;
}