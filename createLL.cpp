#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};
class Stack
{
  Node *head;
  int size = 0;

public:
  Stack()
  {
    this->head = NULL;
  }
  void push(int data)
  {
    Node *new_node = new Node(data);
    if (head == NULL)
    {
      head = new_node;
      size++;
    }
    else
    {
      new_node->next = head;
      head = new_node;
      size++;
    }
  }
  int pop()
  {
    if (size == 0)
    {
      return 0;
    }
    Node *temp = head;
    head = head->next;
    int del = temp->data;
    delete temp;
    size--;
    return del;
  }
  int top()
  {
    if (size == 0)
    {
      return 0;
    }
    int matter = head->data;
    return matter;
  }
  int get_size()
  {
    return size;
  }
  bool isEmpty()
  {
    if (size > 0)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
};
int main()
{
  Stack st;
  int choice;
  cin >> choice;
  int input;
  while (choice != -1)
  {
    if (choice == 1)
    {
      cin >> input;
      st.push(input);
    }
    else if (choice == 2)
    {
      int ans = st.pop();
      if (ans != 0)
      {
        cout << ans << endl;
      }
      else
      {
        cout << "-1" << endl;
      }
    }
    else if (choice == 3)
    {
      int ans = st.top();
      if (ans != 0)
      {
        cout << ans << endl;
      }
      else
      {
        cout << "-1" << endl;
      }
    }
    else if (choice == 4)
    {
      cout << st.get_size() << endl;
    }
    else
    {
      cout << st.isEmpty() << endl;
    }
    cin >> choice;
  }
  return 0;
}
