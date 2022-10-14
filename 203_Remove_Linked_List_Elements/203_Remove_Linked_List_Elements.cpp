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
  void addNode(ListNode **head_ref, int new_data)
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
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *dummyPtr = new ListNode();
    dummyPtr->next = head;
    ListNode *deletePtr = dummyPtr;
    while (deletePtr->next)
    {
      if (deletePtr->next->val == val)
      {
        ListNode *removePtr = deletePtr->next;
        deletePtr->next = deletePtr->next->next;
        delete removePtr;
      }
      else
      {
        deletePtr = deletePtr->next;
      }
    }
    return dummyPtr->next;
  }
};

int main(int argc, char **argv)
{

  Solution obj;
  ListNode *head = NULL;

  obj.addNode(&head, 7);
  obj.addNode(&head, 7);
  obj.addNode(&head, 7);

  ListNode *result = obj.removeElements(head, 7);

  while (result != NULL)
  {
    std::cout << result->val;
    result = result->next;
  }

  std::cout << std::endl;
  return 0;
}