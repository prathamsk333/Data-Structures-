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
    TreeNode* treefinder(vector<int>& preorder, vector<int>& inorder, int start, int end, int& index) {
        if (start > end)
            return nullptr;

        int rootval = preorder[index];
        index++;

        int pos = start;
        for (int i = start; i <= end; i++) {
            if (rootval == inorder[i]) {
                pos = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootval);
        root->left = treefinder(preorder, inorder, start, pos - 1, index);
        root->right = treefinder(preorder, inorder, pos + 1, end, index);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return treefinder(preorder, inorder, 0, preorder.size() - 1, index);
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
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
