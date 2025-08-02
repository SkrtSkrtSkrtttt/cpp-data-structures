//Naafiul Hossain
//SBU ID: 115105623 

#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value, Node* p = nullptr, Node* n = nullptr)
        : data(value), prev(p), next(n) {}
};

Node* removeDuplicates(Node* head) {
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* nextUnique = current->next->next;
            delete current->next;
            current->next = nextUnique;
            if (nextUnique != nullptr) {
                nextUnique->prev = current;
            }
        }
        else {
            current = current->next;
        }
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " <=> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Example usage:
    // Create a sorted doubly linked list: 1 <=> 2 <=> 2 <=> 3 <=> 4 <=> 4 <=> 4 <=> 5
    Node* head = new Node(1);
    head->next = new Node(2, head);
    head->next->next = new Node(2, head->next);
    head->next->next->next = new Node(3, head->next->next);
    head->next->next->next->next = new Node(4, head->next->next->next);
    head->next->next->next->next->next = new Node(4, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(4, head->next->next->next->next->next);
    head->next->next->next->next->next->next->next = new Node(5, head->next->next->next->next->next->next);

    std::cout << "Original Doubly Linked List:" << std::endl;
    printList(head);

    head = removeDuplicates(head);

    std::cout << "\nDoubly Linked List after Removing Duplicates:" << std::endl;
    printList(head);

    // Clean up memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
