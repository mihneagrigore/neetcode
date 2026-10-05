#define INF 2147483647

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int viz[101][101] = {0};
        queue<pair<int, pair<int, int>>> pq;

        for(int i = 0; i < grid.size(); ++i)        
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == 0) {
                    pq.push({0, {i, j}});
                    viz[i][j] = 1;
                }

        while(!pq.empty()) {
            int currDim = pq.front().first;
            int curri = pq.front().second.first, currj = pq.front().second.second;
            pq.pop();

            if(curri - 1 >= 0 && !viz[curri-1][currj] && grid[curri-1][currj] == INF) {
                pq.push({currDim +1, {curri-1, currj}});
                viz[curri-1][currj] = 1;
                grid[curri-1][currj] = currDim + 1;
            }  
            
            if(currj - 1 >= 0 && !viz[curri][currj-1] && grid[curri][currj-1] == INF) {
                pq.push({currDim +1, {curri, currj-1}});
                viz[curri][currj-1] = 1;
                grid[curri][currj-1] = currDim + 1;
            } 

            if(curri + 1 < grid.size() && !viz[curri+1][currj] && grid[curri+1][currj] == INF) {
                pq.push({currDim +1, {curri+1, currj}});
                viz[curri+1][currj] = 1;
                grid[curri+1][currj] = currDim + 1;
            } 

            if(currj + 1 < grid[0].size() && !viz[curri][currj+1] && grid[curri][currj+1] == INF) {
                pq.push({currDim +1, {curri, currj+1}});
                viz[curri][currj+1] = 1;
                grid[curri][currj+1] = currDim + 1;
            } 
        }
    }
};
