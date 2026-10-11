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

    int countGood(TreeNode* curr, int &maxPath) {
        if(curr == nullptr)
            return 0;

        int leftRes, righRes;
        if(maxPath <= curr->val) {
            return 1 + countGood(curr->left, curr->val) + countGood(curr->right, curr->val);
        } else {
            return countGood(curr->left, maxPath) + countGood(curr->right, maxPath);
        }

    }

    int goodNodes(TreeNode* root) {
        int maximum = -101;
        return countGood(root, maximum);   
    }
};
