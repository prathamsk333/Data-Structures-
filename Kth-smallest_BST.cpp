#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> vec;

    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return vec[k - 1];
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution sol;
    int k = 2; 
    int result = sol.kthSmallest(root, k);

    cout << "The " << k << "-th smallest element in the BST is: " << result << endl;

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
