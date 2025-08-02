//Naafiul Hossain
//115107623
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
Node<Type>* mergeLinkedLists(Node<Type>* list1, Node<Type>* list2, Node<Type>* list3) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    Node<Type>* mergedList = list1;
    while (list1->next != nullptr) {
        list1 = list1->next;
    }
    list1->next = list2;

    if (list3 != nullptr) {
        while (list2->next != nullptr) {
            list2 = list2->next;
        }
        list2->next = list3;
    }

    return mergedList;
}

int main() {
    int arr1[] = { 1, 3, 5,7 };
    int arr2[] = { 2, 4, 6,8 };
    int arr3[] = { 0, 9, 10,11 };

    Node<int>* list1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    Node<int>* list2 = createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    Node<int>* list3 = createLinkedList(arr3, sizeof(arr3) / sizeof(arr3[0]));

    cout << "Merged linked list: " << endl;
    Node<int>* mergedList = mergeLinkedLists(list1, list2, list3);
    printLinkedList(mergedList);

    return 0;
}
