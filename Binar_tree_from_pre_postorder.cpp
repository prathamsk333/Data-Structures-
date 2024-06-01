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
    TreeNode* treehelper(vector<int>& inorder, vector<int>& postorder, int start, int end, int& index) {
        if (start > end)
            return nullptr;

        int rootval = postorder[index];
        int pos = start;
        
        for (int i = start; i <= end; i++) {
            if (rootval == inorder[i]) {
                pos = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(rootval);
        index--;
        root->right = treehelper(inorder, postorder, pos + 1, end, index);
        root->left = treehelper(inorder, postorder, start, pos - 1, index);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size() - 1;
        return treehelper(inorder, postorder, 0, index, index);
    }
};

void printInorder(TreeNode* node) {
    if (node == nullptr)
        return;

    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode* root = sol.buildTree(inorder, postorder);
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;
    return 0;
}
