//Naafiul Hossain
//SBU ID: 115107623 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void insertIntoBST(TreeNode*& root, int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
    }
    else if (value < root->val) {
        insertIntoBST(root->left, value);
    }
    else {
        insertIntoBST(root->right, value);
    }
}

void inOrderTraversalRecursive(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversalRecursive(root->left);
        cout << root->val << " ";
        inOrderTraversalRecursive(root->right);
    }
}

void inOrderTraversalWithoutRecursion(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();

        cout << current->val << " ";

        current = current->right;
    }
}

int main() {
    vector<int> numbers = { 5, 3, 8, 2, 4, 7, 9 };
    TreeNode* root = nullptr;

    // Constructing the BST
    for (int num : numbers) {
        insertIntoBST(root, num);
    }

    // In-order traversal with recursion
    cout << "In-order traversal with recursion: ";
    inOrderTraversalRecursive(root);
    cout << endl;

    // In-order traversal without recursion
    cout << "In-order traversal without recursion: ";
    inOrderTraversalWithoutRecursion(root);
    cout << endl;

    return 0;
}
