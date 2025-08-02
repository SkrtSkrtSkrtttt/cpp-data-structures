//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
using namespace std;

template <typename T>
class DetailedLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;
    size_t count;

public:
    DetailedLinkedList() : head(nullptr), count(0) {}

    void push_back(T value) {
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
        count++;
    }

    bool deleteNode(T value) {
        if (!head) {
            return false;  // List is empty
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return true;
        }

        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }

        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count--;
            return true;
        }

        return false;  // Node not found
    }

    void displayDeletedNodeDetails(T value) {
        if (deleteNode(value)) {
            cout << "Deleted node with value " << value << " at position " << count + 1 << endl;
        }
        else {
            cout << "Node with value " << value << " not found in the list." << endl;
        }
    }

    size_t size() const {
        return count;
    }

    void displayList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~DetailedLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    DetailedLinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    cout << "Original List: ";
    list.displayList();

    list.displayDeletedNodeDetails(3);  // Delete node with value 3
    cout << "Updated List: ";
    list.displayList();

    list.displayDeletedNodeDetails(5);  // Attempt to delete a non-existent node
    cout << "Updated List: ";
    list.displayList();

    return 0;
}
