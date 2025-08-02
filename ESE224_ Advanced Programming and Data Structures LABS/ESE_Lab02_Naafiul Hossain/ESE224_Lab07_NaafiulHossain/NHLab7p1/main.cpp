//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
using namespace std;

template<typename Type>
struct Node {
    Type value;
    Node* next;
    Node() : next(nullptr) {}
    Node(Type x, Node* next = nullptr) : value(x), next(next) {}
    ~Node() {}
};

template<typename Type>
Node<Type>* createLinkedList(Type* arr, int n) {
    if (n <= 0) {
        cout << "Please check your input!" << endl;
        return nullptr;
    }
    Node<Type>* head = new Node<Type>(arr[0]);
    Node<Type>* tmp = head;
    for (int i = 1; i < n; i++) {
        tmp->next = new Node<Type>(arr[i]);
        tmp = tmp->next;
    }
    return head;
}

template <typename Type>
void printLinkedList(Node<Type>* head) {
    while (head) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename Type>
Node<Type>* reverse(Node<Type>* head) {
    Node<Type>* current = head;
    Node<Type>* pre = nullptr;
    Node<Type>* next = nullptr;

    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    cout << "Create linked list from array: " << endl;
    Node<int>* node = createLinkedList(arr, sizeof(arr) / sizeof(arr[0]));
    printLinkedList(node);
    cout << "Reverse linked list: " << endl;
    Node<int>* reversed_node = reverse(node);
    printLinkedList(reversed_node);
    return 0;
}
