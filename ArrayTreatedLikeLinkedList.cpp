// Online C33333333333333333333++ compiler to run C++ program online
#include <iostream>
using namespace std;

int example(int b)
{
    //Array declared
    int A[5]={44,5,3,2,23};
    //size of array to use in loop
    int size=sizeof(A);int current=0;
    for(int j=0;j<size ;j++)
    {
       if(b==A[j])
       {
           if(j<size+1){
            current = j;
            cout<<"Current Position in Array "<< current<<"\n";
            cout<<"Number Matched in Array "<< A[j]<<"\n";
         break;
        }
       }
    }
    return 0;
};
int main() {
    example(23);

    return 0;
}