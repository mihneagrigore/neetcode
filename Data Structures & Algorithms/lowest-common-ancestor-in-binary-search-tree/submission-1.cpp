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

    bool up(TreeNode *curr, TreeNode *dest, unordered_set<TreeNode*> &path) {
        if(curr == nullptr)
            return false;
        
        if(curr == dest) {
            path.insert(curr);
            return true;
        }

        if(up(curr->left, dest, path)) {
            path.insert(curr);
            return true;
        } else if(up(curr->right, dest, path)) {
            path.insert(curr);
            return true;
        }  

        return false;      
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;

        unordered_set<TreeNode*> pVal, qVal;
        pVal.insert(root);
        qVal.insert(root);

        up(root, p, pVal);
        up(root, q, qVal);

        // for(auto x : pVal)
        //     cout<<x->val<<" ";
        // cout<<endl;
        // for(auto x : qVal)
        //     cout<<x->val<<" ";


        while(root != nullptr) {
            if(pVal.contains(root->left) && qVal.contains(root->left))
                root = root->left;
            else if(pVal.contains(root->right) && qVal.contains(root->right)) {
                root = root->right;
            } else {
                break;
            }
        }

        return root;

    }
};
