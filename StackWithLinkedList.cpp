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

    // Pushes an element onto the stack
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pops and returns the top element from the stack
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

    // Destructor to free memory occupied by the linked list
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack stack; // Create an instance of the Stack class
    for (int i = 0; i < 9; i++)
    {
        stack.push(i); // Push the element 'i' onto the stack
        cout << "\nElement " << i << " inserted into the stack.";
    }

    for (int i = 0; i < 12; i++)
    {
        if (!stack.isEmpty())
        {                                                     // Check if the stack is not empty
            cout << "\nThe popped element = " << stack.pop(); // Pop and print the top element of the stack
        }
        else
        {
            cout << "\nStack is empty, cannot pop.";
        }
    }

    return 0;
}
