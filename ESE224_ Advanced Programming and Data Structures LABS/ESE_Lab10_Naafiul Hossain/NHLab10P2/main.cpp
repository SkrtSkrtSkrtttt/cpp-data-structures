//Naafiul Hossain
//SBU ID: 115107623


#include <iostream>

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Doubly linked list class
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to print the doubly linked list
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Function to reverse the doubly linked list
    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }
};

int main() {
    // Create a doubly linked list
    DoublyLinkedList myList;
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    // Print the original list
    std::cout << "Original list: ";
    myList.print();

    // Reverse the list
    myList.reverse();

    // Print the reversed list
    std::cout << "Reversed list: ";
    myList.print();

    return 0;
}
