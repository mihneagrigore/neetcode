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

    void addLevel(TreeNode *curr, int level, vector<vector<int>> &res) {
        
        if(curr->left == nullptr && curr->right == nullptr)
            return;            
        
        vector<int> aux;

        if(curr->left != nullptr) {
            aux.push_back(curr->left->val);
        }
        if(curr->right != nullptr) {
            aux.push_back(curr->right->val);
        }

        if(res.size() > level)
            res[level].insert(res[level].end(), aux.begin(), aux.end());
        else 
            res.push_back(aux);

        if(curr->left != nullptr) {
            addLevel(curr->left, level+1, res);
        }
        if(curr->right != nullptr) {
            addLevel(curr->right, level + 1, res);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        
        vector<vector<int>> result;
        result.push_back({root->val});

        addLevel(root, 1, result);

        return result;
    }
};
