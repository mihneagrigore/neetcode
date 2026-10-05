class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int path[51][51] = {0};
        int max = 0;

        for(int i = 0; i < grid.size(); ++i) 
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1 && path[i][j] == 0) {
                    stack<pair<int, int>> s;
                    int area = 0;

                    s.push({i, j});
                    path[i][j] = 1;

                    while(!s.empty()) {
                        area++;
                        int ui = s.top().first, uj = s.top().second;
                        s.pop();

                        if(ui - 1 >= 0 && grid[ui-1][uj] && !path[ui-1][uj]) {
                            path[ui-1][uj] = 1;
                            s.push({ui-1, uj});
                        }

                        if(uj - 1 >= 0 && grid[ui][uj-1] && !path[ui][uj-1]) {
                            path[ui][uj-1] = 1;
                            s.push({ui, uj-1});
                        }

                        if(ui + 1 < grid.size() && grid[ui+1][uj] && !path[ui+1][uj]) {
                            path[ui+1][uj] = 1;
                            s.push({ui+1, uj});
                        }

                        if(uj + 1 < grid[0].size() && grid[ui][uj+1] && !path[ui][uj+1]) {
                            path[ui][uj+1] = 1;
                            s.push({ui, uj+1});
                        }
                    }

                    if(area > max)
                            max = area;
                }
            }

        return max;
    }
};
