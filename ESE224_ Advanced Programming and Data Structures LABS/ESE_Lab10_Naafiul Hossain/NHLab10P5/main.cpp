//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include <climits>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isMaxHeap(Node* root) {
    if (root == NULL) {
        return true;
    }

    // Check the max heap property at the current node
    if (root->left != NULL && root->data < root->left->data) {
        return false;
    }

    if (root->right != NULL && root->data < root->right->data) {
        return false;
    }

    // Recursively check the max heap property for left and right subtrees
    if (!isMaxHeap(root->left) || !isMaxHeap(root->right)) {
        return false;
    }

    return true;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);

    if (isMaxHeap(root)) {
        std::cout << "The binary tree is a max heap." << std::endl;
    }
    else {
        std::cout << "The binary tree is not a max heap." << std::endl;
    }

    return 0;
}