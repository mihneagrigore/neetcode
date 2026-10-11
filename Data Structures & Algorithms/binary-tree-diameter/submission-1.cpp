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

    int diameter(TreeNode *root, int &res) {
        if(root == nullptr)
            return 0;

        int toLeft = diameter(root->left, res);
        int toRight = diameter(root->right, res);

        res = max(res, toLeft + toRight);

        return max(toLeft, toRight) + 1; 
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;

        diameter(root, res);

        return res; 
    }
};
