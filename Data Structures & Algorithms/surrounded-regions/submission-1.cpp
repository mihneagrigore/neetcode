class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int vis[201][201] = {0};

        for(int i = 0; i < board.size(); ++i)   
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == 'O' && !vis[i][j]) {
                    set<pair<int, int>> s;

                    s.insert({i, j});
                    q.push({i, j});
                    vis[i][j] = 1;

                    while(!q.empty()) {
                        int curri = q.front().first, currj = q.front().second;
                        q.pop();

                        if(curri - 1 >= 0 && board[curri-1][currj] == 'O' && !vis[curri-1][currj]) {
                            q.push({curri-1, currj});
                            vis[curri-1][currj] = 1;
                            s.insert({curri-1, currj});
                        }

                        if(currj - 1 >= 0 && board[curri][currj-1] == 'O' && !vis[curri][currj-1]) {
                            q.push({curri, currj-1});
                            vis[curri][currj-1] = 1;
                            s.insert({curri, currj-1});
                        }

                        if(curri + 1 < board.size() && board[curri+1][currj] == 'O' && !vis[curri+1][currj]) {
                            q.push({curri+1, currj});
                            vis[curri+1][currj] = 1;
                            s.insert({curri+1, currj});
                        }

                         if(currj + 1 < board[0].size() && board[curri][currj+1] == 'O' && !vis[curri][currj+1]) {
                            q.push({curri, currj+1});
                            vis[curri][currj+1] = 1;
                            s.insert({curri, currj+1});
                        }
                    }

                    bool isSurr = true;
                    for(auto p : s) {
                        if(p.first == 0 || p.first == board.size()-1 || p.second == 0 || p.second == board[0].size()-1)
                            isSurr = false;
                    }

                    if(isSurr) 
                        for(auto p : s) {
                            board[p.first][p.second] = 'X';
                        }
                }
    }
};
