class PrefixTree {

    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            for(int i = 0; i < 26; ++i)
                child[i] = nullptr;

            isEnd = false;
        }
    };  

    TrieNode *root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        while(word.size() != 0) {
            int firstIdx = word[0] - 'a';

            if(curr->child[firstIdx] != nullptr) {
                curr = curr->child[firstIdx];
            } else {
                TrieNode *aux = new TrieNode();
                curr->child[firstIdx] = aux;
                curr = aux;
            }

            word = word.substr(1);
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;

        while(word.size() != 0) {
            int currIdx = word[0] - 'a';

            if(curr->child[currIdx] == nullptr)
                return false;

            curr = curr->child[currIdx];

            word = word.substr(1);
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;

        while(prefix.size() != 0) {
            int currIdx = prefix[0] - 'a';

            if(curr->child[currIdx] == nullptr)
                return false;

            curr = curr->child[currIdx];
            prefix = prefix.substr(1);
        }

        return true;
    }
};
