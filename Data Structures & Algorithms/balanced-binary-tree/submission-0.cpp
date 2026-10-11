/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int height(TreeNode *root, int &k) {
        if(root == nullptr)
            return 0;

        int left = height(root->left, k);
        int right = height(root->right, k);

        if(k < abs(left-right))
            k = abs(left-right);

        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        int k = 0;
        height(root, k);

        if(k > 1)
            return false;

        return true;
    }
};
