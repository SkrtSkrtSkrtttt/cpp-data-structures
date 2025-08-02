//Naafiul Hossain
//SBU ID: 115107623 
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Definition of binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    if (left == NULL || right == NULL) {
        return false;
    }
    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return isMirror(root->left, root->right);
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Checking if the binary tree is symmetric or not
    if (isSymmetric(root)) {
        cout << "The given binary tree is symmetric." << endl;
    }
    else {
        cout << "The given binary tree is not symmetric." << endl;
    }
    return 0;
}
