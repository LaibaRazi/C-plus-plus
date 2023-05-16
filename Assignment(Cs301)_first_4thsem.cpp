#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
private:
    int object;
    Node *nextNode;

public:
    void set(int value)
    {
        object = value;
    }
    int get() { return object; }

    void setNext(Node *address)
    {
        nextNode = address;
    }
    Node *getNext()
    {
        return nextNode;
    }
};

class list
{
private:
    Node *Head;
    Node *Odd;
    Node *Even;
    Node *Tail;
    Node *Odd_Tail;
    Node *Even_Tail;

public:
    list()
    {
        Head = NULL;
        Odd = NULL;
        Even = NULL;
        Tail = NULL;
        Odd_Tail = NULL;
        Even_Tail = NULL;
    }
    void insert()
    {
        int value;
        cout << "\nEnter Numeric Character of Your Vu ID :";
        cin >> value;
        Node *newNode = new Node;
        newNode->set(value);
        newNode->setNext(NULL);
        if (Head == NULL)
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            Tail->setNext(newNode);
            Tail = newNode;
        }
    }
    void Odd_List()
    {
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (ptr->get() % 2 != 0)
            {
                Node *newNode = new Node;
                newNode->set(ptr->get());
                newNode->setNext(NULL);
                if (Odd == NULL)
                {
                    Odd = newNode;
                    Odd_Tail = newNode;
                }
                else
                {
                    Odd_Tail->setNext(newNode);
                    Odd_Tail = newNode;
                }
            }
            ptr = ptr->getNext();
        }
        ptr = Odd;
        while (ptr != NULL)
        {
            cout << "List Element " << ptr->get() << "\n";
            ptr = ptr->getNext();
        }
    }

    void Even_list()
    {
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (ptr->get() % 2 == 0)
            {
                Node *newNode = new Node;
                newNode->set(ptr ->get());
                newNode->setNext(NULL);
                if (Even == NULL)
                {
                    Even = newNode;
                    Even_Tail = newNode;
                }
                else
                {
                    Even_Tail->setNext(newNode);
                    Even_Tail = newNode;
                }
            }
            ptr = ptr->getNext();
        }
        ptr = Even;
        while (ptr != NULL)
        {
            cout << "List Element" << ptr->get() << "\n";
            ptr = ptr->getNext();
        }
    }

    void Merge_List()
    {
        Head=NULL;
        Node* ptr = Odd;
        while(ptr != NULL)
        {
            Node* newNode =new Node;
            newNode -> set(ptr -> get());
            newNode -> setNext(NULL);
            if(Head == NULL)
            {
               Head=newNode;
               Tail = newNode;
            }
            else
            {
                Tail-> setNext(newNode);
                Tail = newNode;
            }
            ptr = ptr -> getNext();
        }
        ptr =Even;
        while(ptr != NULL)
        {
            Node* newNode = new Node;
            newNode ->set(ptr -> get());
            newNode -> setNext(NULL);
            Tail -> setNext(newNode);
            Tail = newNode;
            ptr = ptr -> getNext();
        }
        ptr =Head;
            while (ptr != NULL)
            {
             cout<<"List Element"<<ptr ->get()<<"\n";
             ptr =ptr ->getNext();
            }
            
        
    }
};
int main()
{
    list L;
    for(int i=1;i<=9;i++)
    {
        L.insert();}
        cout<<"\n\n *****OutPut***** \n\n Odd List \n\n";
        L.Odd_List();
        cout<<"\n Even List \n\n";
        L.Even_list();
        cout<<"\n\n Merge List \n\n";
        L.Merge_List();
        
    
    return 0;
}
