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

    void addNodes(TreeNode *curr, int level, vector<int> &res) {
        if(curr == nullptr)
            return;

        if(res.size() > level)
            res[level] = curr->val;
        else
            res.push_back(curr->val);

        addNodes(curr->left, level+1, res);
        addNodes(curr->right, level+1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        addNodes(root, 0, result);

        return result;
    }
};
