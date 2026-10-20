class Solution {

struct TrieNode {
    TrieNode* child[26];
    bool isEnd, found;

    TrieNode() {
        for(int i = 0; i < 26; ++i)
            child[i] = nullptr;

        isEnd = false;
        found = false;
    }
};  

    TrieNode *root;

public:

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

    void check(int i, int j, vector<vector<char>>& board, TrieNode *curr, string result, vector<string> &words) {

        if(curr->isEnd == true)
            if(curr->found == false) {
                words.push_back(result);
                curr->found = true;
            }

        char aux = board[i][j];
        board[i][j] = '.';

        bool checkRes = false;

        if(i-1 >= 0 && board[i-1][j] != '.' && curr->child[board[i-1][j] - 'a'] != nullptr) 
            check(i-1, j, board, curr->child[board[i-1][j] - 'a'], result + board[i-1][j], words);

        if(j-1 >= 0 && board[i][j-1] != '.' && curr->child[board[i][j-1] - 'a'] != nullptr) 
            check(i, j-1, board, curr->child[board[i][j-1] - 'a'], result + board[i][j-1], words);

        if(i+1 < board.size() && board[i+1][j] != '.' && curr->child[board[i+1][j] - 'a'] != nullptr) 
            check(i+1, j, board, curr->child[board[i+1][j] - 'a'], result + board[i+1][j], words);

        if(j+1 < board[0].size() && board[i][j+1] != '.' && curr->child[board[i][j+1] - 'a'] != nullptr) 
            check(i, j+1, board, curr->child[board[i][j+1] - 'a'], result + board[i][j+1], words);

        board[i][j] = aux;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        vector<string> result;

        root = new TrieNode();

        for(auto s : words) {
            insert(s);
        }

        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j) {

                if(root->child[board[i][j] - 'a'] != nullptr) {
                    vector<string> aux;
                    check(i, j, board, root->child[board[i][j] - 'a'], string(1, board[i][j]), aux);
                    result.insert(result.end(), aux.begin(), aux.end());
                }
            }

        return result;
    }
};
