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

#include <limits.h>

class Solution {
public:

    int maxSum = INT_MIN;

    int sum(TreeNode *curr) {
        if(curr->left == nullptr && curr->right == nullptr) {
            if(curr->val <= 0) {
                maxSum = max(maxSum, curr->val);
                return 0;
            } else {
                maxSum = max(maxSum, curr->val);
                return curr->val;
            }
        }

        int sumLeft = 0, sumRight = 0;
        if(curr->left != nullptr)
            sumLeft = sum(curr->left);
        if(curr->right != nullptr)
            sumRight = sum(curr->right);

        int totalSum = curr->val + sumLeft + sumRight;

        maxSum = max(maxSum, totalSum);

        return curr->val + max(sumLeft, sumRight);
    }

    int maxPathSum(TreeNode* root) {

        sum(root);
        return maxSum;
    }
};
