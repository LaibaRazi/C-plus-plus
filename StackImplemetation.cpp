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
    int top(){return A[current];}
    int isEmpty(){return (current==-1);}
    int isFull(){return (current ==size-1);}

    private:
    int object;
    int current;
    int size;
    int A[10];
};
int main()
{
    stack stack;
    for(int i=0;i<12;i++)
    {
        if(!stack.isFull()){
        stack.push(i);
        cout<<"\n stack inserted new element";}
        else{
        cout<<"\n stack is full,can't insert new element";}

    }
    for(int i=0;i<12;i++)
    {
        if(!stack.isEmpty())
        cout<<"\n the popped element ="<<stack.pop();
        else
        cout <<"\n stack is empty ,can't pop";
    }
}