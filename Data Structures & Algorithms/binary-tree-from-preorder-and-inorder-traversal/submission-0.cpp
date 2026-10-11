class Solution {
public:
    unordered_map<int, int> inord;
    int idx = 0;

    TreeNode* insert(vector<int>& preorder, int l, int r) {
        if (l > r)
            return nullptr;

        int val = preorder[idx++];
        TreeNode* curr = new TreeNode(val);

        int mid = inord[val];

        curr->left = insert(preorder, l, mid - 1);
        curr->right = insert(preorder, mid + 1, r);

        return curr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i)
            inord[inorder[i]] = i;

        idx = 0;
        return insert(preorder, 0, inorder.size() - 1);
    }
};