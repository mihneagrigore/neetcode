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

#define MIN_VAL -1000000001
#define MAX_VAL 1000000001

class Solution {
public:

    bool valid(TreeNode *curr, int minVal, int maxVal) {
        if(curr == nullptr) 
            return true;

        // cout<<curr->val<<" "<<minVal<<" "<<maxVal<<endl;

        if(curr->val >= minVal || curr->val <= maxVal) {
            return false;
        }

        return valid(curr->left, min(curr->val, minVal), maxVal) && valid(curr->right, minVal, max(maxVal, curr->val));
    }

    bool isValidBST(TreeNode* root) {

        if(root == nullptr)
            return true;

        if(root->left == nullptr && root->right == nullptr)
            return true;

        return valid(root->left, root->val, MIN_VAL) && valid(root->right, MAX_VAL, root->val);
    }
};
