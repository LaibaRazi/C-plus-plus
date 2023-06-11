#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }
    void push(int value)
    {
        Node *newNode = new Node(value); // Create a new node with the given value
        newNode->next = topNode;         // Set the next pointer of the new node to the current top node
        topNode = newNode;               // Update the top node to point to the new node
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop an element.\n";
            return -1; // Assuming -1 as an error value
        }

        int poppedValue = topNode->data; // Retrieve the data value of the top node
        Node *temp = topNode;            // Create a temporary pointer to the top node
        topNode = topNode->next;         // Update the top node to point to the next node
        delete temp;                     // Deallocate the memory occupied by the original top node
        return poppedValue;              // Return the popped value
    }
    // Returns the value of the top element without removing it
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return -1; // Assuming -1 as an error value
        }

        return topNode->data;
    }
    // Checks if the stack is empty
    bool isEmpty()
    {
        return (topNode == nullptr);
    }
};
int main()
{
    Stack stack;
    for (int i = 1; i <= 10; i++)
    {
        stack.push(i);
        
    }
    for (int i = 1; i <= 12; i++)
    {
        if (!stack.isEmpty())
        {
           cout << "\nThe popped element = " << stack.pop(); // Pop and print the top element of the stack
        }else
        {
            cout<<"Can't be poped";
        }
    }
    return 0;
}