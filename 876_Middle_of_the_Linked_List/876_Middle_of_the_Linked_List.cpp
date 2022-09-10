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
private:
  ListNode *head, *tail;

public:
  ListNode *middleNode(ListNode *head)
  {
  }

  Solution()
  {
    head = NULL;
    tail = NULL;
  }
  void addNode(int n)
  {
    ListNode *tmp = new ListNode;
    tmp->val = n;
    tmp->next = NULL;

    if (head == NULL)
    {
      head = tmp;
      tail = tmp;
    }
    else
    {
      tail->next = tmp;
      tail = tail->next;
    }
  }
};

int main()
{
  Solution obj;

  obj.addNode(1);
  obj.addNode(2);
  obj.addNode(3);
  obj.addNode(4);
  obj.addNode(5);

  return 0;
}