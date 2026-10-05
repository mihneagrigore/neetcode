class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int pass[101][101] = {0};
        int total = 0;

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == '1' && pass[i][j] == 0) {
                    cout<<i<<" "<<j<<endl;

                    queue<pair<int, int>> pq;
                    int copi = i, copj = j;

                    pq.push({i, j});
                    pass[i][j] = 1;

                    while(!pq.empty()) {
                        int curri = pq.front().first, currj = pq.front().second;
                        pq.pop();

                        if(curri - 1 >= 0 && pass[curri - 1][currj] == 0 && grid[curri - 1][currj] == '1') {
                            pass[curri - 1][currj] = 1;
                            pq.push({curri - 1, currj});
                        }

                        if(currj - 1 >= 0 && pass[curri][currj - 1] == 0 && grid[curri][currj - 1] == '1') {
                            pass[curri][currj - 1] = 1;
                            pq.push({curri, currj - 1});
                        }

                        if(curri + 1 < grid.size() && pass[curri + 1][currj] == 0 && grid[curri + 1][currj] == '1') {
                            pass[curri + 1][currj] = 1;
                            pq.push({curri + 1, currj});
                        }

                        if(currj + 1 < grid[0].size() && pass[curri][currj + 1] == 0 && grid[curri][currj + 1] == '1') {
                            pass[curri][currj + 1] = 1;
                            pq.push({curri, currj + 1});
                        }
                    } 

                total++;
        
                }

        return total;
    }
};
