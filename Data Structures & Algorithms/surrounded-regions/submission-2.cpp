class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }

            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '#';
            }
        }

        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }

            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = '#';
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i > 0 && board[i - 1][j] == 'O') {
                board[i - 1][j] = '#';
                q.push({i - 1, j});
            }

            if (i + 1 < n && board[i + 1][j] == 'O') {
                board[i + 1][j] = '#';
                q.push({i + 1, j});
            }

            if (j > 0 && board[i][j - 1] == 'O') {
                board[i][j - 1] = '#';
                q.push({i, j - 1});
            }

            if (j + 1 < m && board[i][j + 1] == 'O') {
                board[i][j + 1] = '#';
                q.push({i, j + 1});
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};