#include <iostream>
using namespace std;

class Node
{
private:
    int id, quantity;
    double price;
    string name;
    Node *next;

public:
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    int getQuantity()
    {

        return quantity;
    }
    double getPrice()
    {
        return price;
    }
    Node *getNext()
    {

        return next;
    }
};

class Inventory
{
private:
    Node *Head;

public:
    Inventory()
    {
        Head = NULL;
    }
    void addProduct(int id, string name, int quantity, double price)
    {
        Node *newNode = new Node;
        newNode->setId(id);
        newNode->setName(name);
        newNode->setQuantity(quantity);
        newNode->setPrice(price);
        newNode->setNext(NULL);
        if (Head == NULL)
        {
            Head = newNode;
        }
        else
        {
            Node *ptr = Head;
            while (ptr->getNext() != NULL)
            {
                ptr = ptr->getNext();
            }
            ptr->setNext(newNode);
        }
        cout << "Product Added Sucessfully.\n";
    }
    void removeProduct(int id)
    {
        if (Head->getId() == id)
        {
            Node *ptr = Head;
            Head = Head->getNext();
            cout << "Product Removed Succesfully.\n";
            delete ptr;
        }
        else
        {
            Node* pre=Head;
            Node* ptr =Head -> getNext();
            while(ptr != NULL)
            {
                if(ptr -> getId()==id)
                {
                    pre -> setNext(ptr -> getNext());
                    cout<<"Product Removed Succesfully.\n";
                    delete ptr;
                    break;
                }
                pre =ptr;
                ptr = ptr -> getNext();
            }
        }
    }
};

int main() {}