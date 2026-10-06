class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int maxTime = 0;

        queue<pair <int, pair<int, int>>> q;
        int vis[11][11] = {0};

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
        
        while(!q.empty()) {
            int currTime = q.front().first;
            int curri = q.front().second.first, currj = q.front().second.second;
            q.pop();

            if(currTime > maxTime)
                maxTime = currTime;

            if(curri - 1 >= 0 && grid[curri-1][currj] == 1 && !vis[curri-1][currj]) {
                q.push({currTime+1, {curri-1, currj}});
                vis[curri-1][currj] = 1;
                grid[curri-1][currj] = 2;
            }

            if(currj - 1 >= 0 && grid[curri][currj-1] == 1 && !vis[curri][currj-1]) {
                q.push({currTime+1, {curri, currj-1}});
                vis[curri][currj-1] = 1;
                grid[curri][currj-1] = 2;
            }

            if(curri + 1 < grid.size() && grid[curri+1][currj] == 1 && !vis[curri+1][currj]) {
                q.push({currTime+1, {curri+1, currj}});
                vis[curri+1][currj] = 1;
                grid[curri+1][currj] = 2;
            }

            if(currj + 1 < grid[0].size() && grid[curri][currj+1] == 1 && !vis[curri][currj+1]) {
                q.push({currTime+1, {curri, currj+1}});
                vis[curri][currj+1] = 1;
                grid[curri][currj+1] = 2;
            }
        }

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j) 
                if(grid[i][j] == 1)
                    return -1;
        
        return maxTime;        
    }
};
