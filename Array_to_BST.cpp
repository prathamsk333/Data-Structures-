#include <iostream>
#include <vector>

// Definition for a binary tree node.
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
    TreeNode* insert(std::vector<int>& nums, int l, int r) {
        if (l <= r) {
            int mid = (l + r) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = insert(nums, l, mid - 1);
            root->right = insert(nums, mid + 1, r);
            return root;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return insert(nums, 0, nums.size() - 1);
    }
};

// Helper function to print the tree in-order
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Solution solution;
    std::vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);

    std::cout << "In-order traversal of the BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
