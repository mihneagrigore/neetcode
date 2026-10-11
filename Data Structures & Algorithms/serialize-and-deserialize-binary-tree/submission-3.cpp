class Codec {
public:
    string serialize(TreeNode* root) {
        string result;
        writeNode(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        stringstream stream(data);
        return readNode(stream);
    }

private:

    void writeNode(TreeNode* node, string& result) {
        if (node == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(node->val) + ",";   
        writeNode(node->left, result);          
        writeNode(node->right, result);         
    }

    TreeNode* readNode(stringstream& stream) {
        string token;
        getline(stream, token, ',');            

        if (token == "#" || token.empty())
            return nullptr;

        TreeNode* node = new TreeNode(stoi(token));  
        node->left = readNode(stream);             
        node->right = readNode(stream);            
        return node;
    }
};