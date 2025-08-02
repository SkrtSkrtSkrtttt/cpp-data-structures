//Naafiul Hossain
//SBU ID: 115107623 
#include <vector>
#include <queue>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;  // An empty tree has a depth of 0
    }
    else {
        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // The depth of the tree is the maximum depth of the left and right subtrees, plus 1 for the current node
        return max(leftDepth, rightDepth) + 1;
    }
}

int main() {
    

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Maximum Depth: " << maxDepth(root) << endl;

    return 0;
}
