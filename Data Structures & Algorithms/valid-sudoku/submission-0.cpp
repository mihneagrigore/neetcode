class Solution {
public:
    bool checkLine(vector<char> &boardLine) {
        vector<bool> check(10, 0);

        for(int i = 0; i < 9; ++i)
            if(boardLine[i] == '.')
                continue;
            else 
                if(check[boardLine[i] - '0'])
                    return false;
                else 
                    check[boardLine[i] - '0'] = true;

        return true;
    }

    bool checkSq(vector<vector<char>> &board, int line, int col) {
        vector<bool> check(10, 0);

        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                if(board[line + i][col + j] == '.')
                    continue;
                else 
                    if(check[board[line + i][col + j] - '0'])
                        return false;
                    else 
                        check[board[line + i][col + j] - '0'] = true;

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i)
            if(!checkLine(board[i]))
                return false;

        for(int i = 0; i < 9; ++i) {
            vector<char> colTrsp;
            for(int j = 0; j < 9; ++j) 
                colTrsp.push_back(board[j][i]);

            if(!checkLine(colTrsp))
                return false;
        }

        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
                if(!checkSq(board, i, j))
                    return false;

        return true;
    }
};
