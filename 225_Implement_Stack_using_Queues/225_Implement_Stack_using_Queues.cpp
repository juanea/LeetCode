#include <iostream>
#include <queue>

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

class MyStack
{
  std::queue<int> myQueue;

private:
  std::queue<int> reverseQueue(std::queue<int> firstQueue)
  {
    std::queue<int> secondQueue;
    while (!firstQueue.empty())
    {
      for (size_t i = 0; i < firstQueue.size() - 1; i++)
      {
        int movingElement = firstQueue.front();
        firstQueue.pop();
        firstQueue.push(movingElement);
      }
      secondQueue.push(firstQueue.front());
      firstQueue.pop();
    }
    return secondQueue;
  }

public:
  MyStack()
  {
  }

  void push(int x)
  {
    myQueue.push(x);
  }

  int pop()
  {
    std::queue<int> tempQueue = reverseQueue(myQueue);
    int x = tempQueue.front();
    tempQueue.pop();
    while (!myQueue.size())
    {
      myQueue.pop();
    }
    myQueue = reverseQueue(tempQueue);

    return x;
  }

  int top()
  {
    std::queue<int> tempQueue = reverseQueue(myQueue);
    return tempQueue.front();
  }

  bool empty()
  {
    if (myQueue.empty())
      return true;
    else
      return false;
  }
};

int main()
{
  MyStack myStack; // = new MyStack();

  myStack.push(1);
  myStack.push(2);
  std::cout << myStack.top() << std::endl;                     // return 2
  std::cout << myStack.pop() << std::endl;                     // return 2
  std::cout << myStack.pop() << std::endl;                     // return 1
  std::cout << std::boolalpha << myStack.empty() << std::endl; // return true
  return 0;
}