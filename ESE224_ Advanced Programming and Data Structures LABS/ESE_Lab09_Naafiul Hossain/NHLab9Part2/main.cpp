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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* buildtree() {
    TreeNode* root;
    root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);

    return root;
}

void LevelOrderTraversal(TreeNode* root) {
    if (!root) {
        cout << "Tree is Null." << endl;
    }
    else {
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            int qsize = qe.size();
            for (int i = 0; i < qsize; ++i) {
                TreeNode* cur = qe.front();
                qe.pop();
                cout << cur->val << " ";
                if (cur->left != nullptr) {
                    qe.push(cur->left);
                }
                if (cur->right != nullptr) {
                    qe.push(cur->right);
                }
            }
            cout << endl;  // Add this line to print a newline after processing each level
        }
    }
}

bool searchBST(TreeNode* root, int target) {
    if (!root) {
        return false;  // Target not found
    }

    if (root->val == target) {
        return true;  // Target found
    }
    else if (target < root->val) {
        return searchBST(root->left, target);  // Search in the left subtree
    }
    else {
        return searchBST(root->right, target);  // Search in the right subtree
    }
}

int main() {
    TreeNode* root = buildtree();
    cout << "LevelOrderTraversal: ";
    LevelOrderTraversal(root);
     

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    if (searchBST(root, target)) {
        cout << "Target " << target << " is in the tree." << endl;
    }
    else {
        cout << "Target " << target << " is not in the tree." << endl;
    }

    return 0;
}
