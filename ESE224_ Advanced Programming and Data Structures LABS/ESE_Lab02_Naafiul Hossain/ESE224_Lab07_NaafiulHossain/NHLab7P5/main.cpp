//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    fstream inputFile("input.txt");
    string line;

    // Create two linked lists for the values in input.txt
    LinkedList list1, list2;
    vector<int> values1, values2;

    // Read the first line of values
    if (getline(inputFile, line)) {
        stringstream ss(line);
        int value;
        while (ss >> value) {
            values1.push_back(value);
        }
    }

    // Read the second line of values
    if (getline(inputFile, line)) {
        stringstream ss(line);
        int value;
        while (ss >> value) {
            values2.push_back(value);
        }
    }

    // Populate list1 and list2 with the extracted values
    for (int value : values1) {
        list1.push_back(value);
    }

    for (int value : values2) {
        list2.push_back(value);
    }

    // Add corresponding elements and store the result in list3
    LinkedList list3;

    Node* current1 = list1.head;
    Node* current2 = list2.head;

    while (current1 && current2) {
        list3.push_back(current1->data + current2->data);
        current1 = current1->next;
        current2 = current2->next;
    }

    // Print values of all three lists
    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();
    cout << "List 3: ";
    list3.display();

    // Write the data of list3 to output.txt
    ofstream outputFile("output.txt");
    Node* current3 = list3.head;
    while (current3) {
        outputFile << current3->data << " ";
        current3 = current3->next;
    }
    outputFile.close();

    // Manually delete all three lists
    current1 = list1.head;
    while (current1) {
        Node* temp = current1;
        current1 = current1->next;
        delete temp;
    }

    current2 = list2.head;
    while (current2) {
        Node* temp = current2;
        current2 = current2->next;
        delete temp;
    }

    current3 = list3.head;
    while (current3) {
        Node* temp = current3;
        current3 = current3->next;
        delete temp;
    }

    inputFile.close();
    return 0;
}
