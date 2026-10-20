class WordDictionary {

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
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool searchFrom(const string &word, int pos, TrieNode *curr) {
        if(word.size() == pos) {
            if(curr->isEnd == true)
                return true;
            else
                return false;
        }

        if(word[pos] == '.') {

            bool result = false;

            for(int c = 0; c < 26; ++c) {
                if(curr->child[c] == nullptr)
                    continue;
                
                result = result || searchFrom(word, pos+1, curr->child[c]);
            }

            return result;
        } else {
            if(curr->child[word[pos] - 'a'] == nullptr)
                return false;

            return searchFrom(word, pos+1, curr->child[word[pos] - 'a']);
        }
    } 

    bool search(string word) {
        return searchFrom(word, 0, root);
    }
};
