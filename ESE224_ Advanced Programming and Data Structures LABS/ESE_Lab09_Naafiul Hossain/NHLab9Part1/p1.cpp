//Naafiul Hossian
//SBU ID: 115107623

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

TreeNode* buildtree() {
	TreeNode* root;
	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);

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


int main() {
	TreeNode* root = buildtree();
	cout << "LevelOrderTraversal:";
    LevelOrderTraversal(root);
	return 0;
}