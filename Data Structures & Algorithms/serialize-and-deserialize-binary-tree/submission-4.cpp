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

#define ROOT_PARENT "1001"

class Codec {

    int nodeId;

public:

    void doSerialize(TreeNode *curr, string &result, int currId) {

        if(curr == nullptr)
            return;

        if(curr->left != nullptr) {
            int leftId = nodeId++;

            result.append(to_string(currId));
            result.push_back(':');
            result.append(to_string(curr->val));
            result.append(":l:");
            result.append(to_string(leftId));
            result.push_back(':');
            result.append(to_string(curr->left->val));
            result.push_back(',');

            doSerialize(curr->left, result, leftId);
        } 

        if(curr->right != nullptr) {
            int rightId = nodeId++;

            result.append(to_string(currId));
            result.push_back(':');
            result.append(to_string(curr->val));
            result.append(":r:");
            result.append(to_string(rightId));
            result.push_back(':');
            result.append(to_string(curr->right->val));
            result.push_back(',');

            doSerialize(curr->right, result, rightId);
        }
            
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;

        if(root == nullptr)
            return result;

        result.reserve(1024);
        result.append(ROOT_PARENT);
        result.append(":0:");
        result.append(to_string(root->val));
        result.push_back(',');

        nodeId = 1;
        doSerialize(root, result, 0);

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        unordered_map<int, TreeNode*> nodes;
        stringstream ss(data);
        string part;
        TreeNode* root = nullptr;

        while (getline(ss, part, ',')) {
            stringstream ssPart(part);
            string token;
            vector<string> a;

            while (getline(ssPart, token, ':'))
                a.push_back(token);

            if (a[0] == ROOT_PARENT) {
                root = new TreeNode(stoi(a[2]));
                nodes[0] = root;
                continue;
            }

            int parentId = stoi(a[0]);
            int childId = stoi(a[3]);
            int childVal = stoi(a[4]);

            TreeNode* parent = nodes[parentId];
            TreeNode* child = new TreeNode(childVal);

            nodes[childId] = child;

            if (a[2] == "l")
                parent->left = child;
            else
                parent->right = child;
        }

        return root;
    }
};
