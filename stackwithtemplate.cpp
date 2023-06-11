#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T value)
    {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack
{
private:
    Node<T> *topNode;

public:
    Stack()
    {
        topNode = nullptr;
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop an element.\n";
            return T(); // Assuming T() as a default value for error cases
        }

        T poppedValue = topNode->data;
        Node<T> *temp = topNode;
        topNode = topNode->next;
        delete temp;
        return poppedValue;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return T(); // Assuming T() as a default value for error cases
        }

        return topNode->data;
    }

    bool isEmpty()
    {
        return (topNode == nullptr);
    }

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
    Stack<int> stack;
    for (int i = 0; i < 9; i++)
    {
        stack.push(i);
        cout << "\nElement " << i << " inserted into the stack.";
    }

    for (int i = 0; i < 12; i++)
    {
        if (!stack.isEmpty())
        {
            cout << "\nThe popped element = " << stack.pop();
        }
        else
        {
            cout << "\nStack is empty, cannot pop.";
        }
    }

    return 0;
}
