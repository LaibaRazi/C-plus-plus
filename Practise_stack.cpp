#include <iostream>
using namespace std;

class stack
{
public:
    stack()
    {
        size = 10;
        current = -1;
    }
    int pop()
    {
        return A[current--];
    }
    void push(int x)
    {
        A[++current] = x;
    }
    int top()
    {
        return A[current];
    }
    int isEmpty() { return (current == -1); }
    int isFull() { return (current == size - 1); }

private:
    int size;
    int current;
    int object;
    int A[10];
};

int main()
{
    stack stack;
 for (int i = 0; i <=12; i++)
 {
    if(!stack.isFull()){
    stack.push(i);}
    else{
        cout<<"\nStack is full";
    }

 }
 for (int i = 0; i <=12; i++)
 {
    if(!stack.isEmpty())
    {
        cout<<" \n Poped values "<<stack.pop();
    }
    else
    {
        cout<<"\nNot Enough values "<<endl;
    }

 }
 


    return 0;
}