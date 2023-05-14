#include <iostream>
#

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void separateEvenOdd(LinkedList& evenList, LinkedList& oddList) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data % 2 == 0) {
                evenList.insert(current->data);
            } else {
                oddList.insert(current->data);
            }
            current = current->next;
        }
    }

    void merge(LinkedList& list1, LinkedList& list2) {
        Node* temp = list1.head;

        if (temp == nullptr) {
            head = list2.head;
            return;
        }

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = list2.head;
        head = list1.head;
    }
};

int main() {
    LinkedList linkedList;
    LinkedList evenList;
    LinkedList oddList;

    int vuID[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Replace with your VU ID digits

    for (int i = 0; i < sizeof(vuID) / sizeof(vuID[0]); i++) {
        linkedList.insert(vuID[i]);
    }

    linkedList.separateEvenOdd(evenList, oddList);
    linkedList.merge(oddList, evenList);

    cout << "Odd digits: ";
    oddList.display();

    cout << "Even digits: ";
    evenList.display();

    cout << "Merged list: ";
    linkedList.display();

    return 0;
}
