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

    vector<int> res;

    void construct(TreeNode *root, int k) {
        if(res.size() == k)
            return;

        if(root == nullptr)
            return;

        if(root->left != nullptr)
            construct(root->left, k);
            
        res.push_back(root->val);

        if(res.size() == k)
            return;

        if(root->right != nullptr) 
            construct(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        construct(root, k);
        return res[k-1];
    }
};
