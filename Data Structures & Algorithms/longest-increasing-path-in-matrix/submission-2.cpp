class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if(matrix.size() == 0)
            return 0;

        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 1));

        priority_queue <pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;


        for(int i = 0; i < matrix.size(); ++i)
            for(int j = 0; j < matrix[0].size(); ++j)
                pq.push({matrix[i][j], {i, j}});

        while(!pq.empty()) {
            int topVal = pq.top().first, topi = pq.top().second.first, topj = pq.top().second.second;
            pq.pop();

            if(topi + 1 < matrix.size() && topVal < matrix[topi+1][topj] && dp[topi+1][topj] < dp[topi][topj]+1) {
                dp[topi+1][topj] = dp[topi][topj] + 1;
                pq.push({matrix[topi+1][topj], {topi+1, topj}});
            }

            if(topi - 1 >= 0 && topVal < matrix[topi-1][topj] && dp[topi-1][topj] < dp[topi][topj]+1) {
                dp[topi-1][topj] = dp[topi][topj] + 1;
                pq.push({matrix[topi-1][topj], {topi-1, topj}});
            }

            if(topj + 1 < matrix[0].size() && topVal < matrix[topi][topj+1] && dp[topi][topj+1] < dp[topi][topj]+1) {
                dp[topi][topj+1] = dp[topi][topj] + 1;
                pq.push({matrix[topi][topj+1], {topi, topj+1}});
            }

            if(topj - 1 >= 0 && topVal < matrix[topi][topj-1] && dp[topi][topj-1] < dp[topi][topj]+1) {
                dp[topi][topj-1] = dp[topi][topj]+1;
                pq.push({matrix[topi][topj-1], {topi, topj-1}});
            }
        }

        int result = 0;
        for(int i = 0; i < dp.size(); ++i)
            for(int j = 0; j < dp[0].size(); ++j) 
                if(result < dp[i][j])
                    result = dp[i][j];
        
        return result;
    }
};
