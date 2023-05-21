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
            Node *pre = Head;
            Node *ptr = Head->getNext();
            while (ptr != NULL)
            {
                if (ptr->getId() == id)
                {
                    pre->setNext(ptr->getNext());
                    cout << "Product Removed Succesfully.\n";
                    delete ptr;
                    break;
                }
                pre = ptr;
                ptr = ptr->getNext();
            }
        }
    }
    void updateProduct(int id, int quantity, double price)
    {
        Node *ptr = Head;
        while (ptr != NULL)
        {
            if (ptr->getId() == id)
            {
                ptr->setQuantity(quantity);
                ptr->setPrice(price);
                cout << "Product Updated Succesfully\n";
            }
            ptr = ptr->getNext();
        }
    }
    void displayInventory()
    {
        cout << "Inventory:\nName\tID\tQuantity\tPrice\n";
        Node *ptr = Head;
        while (ptr != NULL)
        {
            cout << ptr->getName();
            cout << "\t" << ptr->getId();
            cout << "\t" << ptr->getQuantity();
            cout << "\t\t" << ptr->getPrice();
            cout<<"\n";
            ptr = ptr->getNext();
        }
    }
};

int main()
{
    Inventory obj;
p:
    int choice, id, quantity, number_of_products;
    double price;
    string name;
    cout << "Please choose an Action:\n";
    cout << "1. Add Product \n";
    cout << "2. Remove Product \n";
    cout << "3. Update Product \n";
    cout << "4. Display Product \n";
    cout << "0. Exit \n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "How Many Products do you want to add?";
        cin >> number_of_products;
        for (int i = 1; i <= number_of_products; i++)
        {
            cout << "Enter Product Id:";
            cin >> id;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Product Quantity: ";
            cin >> quantity;
            cout << "Enter Product Price: ";
            cin >> price;
            obj.addProduct(id, name, quantity, price);
        }
        break;
    case 2:

        cout << "Enter Product ID to Remove";
        cin >> id;
        obj.removeProduct(id);
        break;
    case 3:
        cout << "Enter Product ID to Update:";
        cin >> id;
        cout << "Enter New Quantity:";
        cin >> quantity;
        cout << "Enter New Price :";
        cin >> price;
        obj.updateProduct(id, quantity, price);
        break;
    case 4:
        obj.displayInventory();
        break;
    case 0:
        exit(0);
    default:
        cout << "\n \n Invalid Choice";
    }
    goto p;
    return 0;
}