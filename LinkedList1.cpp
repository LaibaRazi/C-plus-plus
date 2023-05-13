#include <iostream>
#include <stdlib.h>
using namespace std;

// Node Made Out of Structure
struct Node
{
    int data;          // Data value stored in the node
    struct Node *next; // Pointer to the next node
};

int main()
{
    struct Node *head;   // Pointer to the first node (head) of the linked list
    struct Node *second; // Pointer to the second node
    struct Node *third;  // Pointer to the third node

    // Dynamically allocate memory for each node
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data values and link nodes together

    head->data = 7;
    head->next = second;

    second->data = 111;
    second->next = third;

    third->data = 200;
    // third->next =  ;

    // Print the data values and next pointers of each node
    cout << "Head " << head->data << "\n"
         << head->next << endl;
    cout << "Second " << second->data << "\n"
         << second->next << endl;
    cout << "Third " << third->data << "\n"
         << third->next << endl;

    return 0;
}