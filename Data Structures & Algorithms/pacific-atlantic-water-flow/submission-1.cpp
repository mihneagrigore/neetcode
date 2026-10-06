class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int visPacific[101][101] = {0}, visAtlantic[101][101] = {0};
        set<pair<int, int>> pacific, atlantic;

        //pacific

        for(int i = 0; i < grid.size(); ++i) {
            q.push({i, 0});
            visPacific[i][0] = 1;
            pacific.insert({i, 0});
        }

        for(int i = 0; i < grid[0].size(); ++i) {
            q.push({0, i});
            visPacific[0][i] = 1;
            pacific.insert({0, i});
        }
        
        while(!q.empty()) {
            int curri = q.front().first, currj = q.front().second;
            q.pop();

            if(curri - 1 >= 0 && grid[curri-1][currj] >= grid[curri][currj] && !visPacific[curri-1][currj]) {
                q.push({curri-1, currj});
                visPacific[curri-1][currj] = 1;
                pacific.insert({curri-1, currj});
            }

            if(currj - 1 >= 0 && grid[curri][currj-1] >= grid[curri][currj] && !visPacific[curri][currj-1]) {
                q.push({curri, currj-1});
                visPacific[curri][currj-1] = 1;            
                pacific.insert({curri, currj-1});
            }

            if(curri + 1 < grid.size() && grid[curri+1][currj] >= grid[curri][currj]&& !visPacific[curri+1][currj]) {
                q.push({curri+1, currj});
                visPacific[curri+1][currj] = 1;
                pacific.insert({curri+1, currj});
            }

            if(currj + 1 < grid[0].size() && grid[curri][currj+1] >= grid[curri][currj] && !visPacific[curri][currj+1]) {
                q.push({curri, currj+1});
                visPacific[curri][currj+1] = 1;
                pacific.insert({curri, currj+1});
            }
        }

        // atlantic

        for(int i = 0; i < grid.size(); ++i) {
            q.push({i, grid[0].size()-1});
            visAtlantic[i][grid[0].size()-1] = 1;
            atlantic.insert({i, grid[0].size()- 1});
        }

        for(int i = 0; i < grid[0].size(); ++i) {
            q.push({grid.size()-1, i});
            visAtlantic[grid.size()-1][i] = 1;
            atlantic.insert({grid.size()-1, i});
        }
        
        while(!q.empty()) {
            int curri = q.front().first, currj = q.front().second;
            q.pop();

            if(curri - 1 >= 0 && grid[curri-1][currj] >= grid[curri][currj] && !visAtlantic[curri-1][currj]) {
                q.push({curri-1, currj});
                visAtlantic[curri-1][currj] = 1;
                atlantic.insert({curri-1, currj});
            }

            if(currj - 1 >= 0 && grid[curri][currj-1] >= grid[curri][currj] && !visAtlantic[curri][currj-1]) {
                q.push({curri, currj-1});
                visAtlantic[curri][currj-1] = 1;            
                atlantic.insert({curri, currj-1});
            }

            if(curri + 1 < grid.size() && grid[curri+1][currj] >= grid[curri][currj]&& !visAtlantic[curri+1][currj]) {
                q.push({curri+1, currj});
                visAtlantic[curri+1][currj] = 1;
                atlantic.insert({curri+1, currj});
            }

            if(currj + 1 < grid[0].size() && grid[curri][currj+1] >= grid[curri][currj] && !visAtlantic[curri][currj+1]) {
                q.push({curri, currj+1});
                visAtlantic[curri][currj+1] = 1;
                atlantic.insert({curri, currj+1});
            }
        }

        // result

        vector<vector<int>> result;
        for(auto x : pacific)
            if(atlantic.find(x) != atlantic.end()) {
                vector<int> aux;
                aux.push_back(x.first);
                aux.push_back(x.second);

                result.push_back(aux);
            }

        return result;
    }
};
