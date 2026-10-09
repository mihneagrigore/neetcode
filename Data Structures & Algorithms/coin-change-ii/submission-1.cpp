class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size() + 1, 0));

        for(auto x : coins)
            if(x <= amount)
                dp[x][1] = 1;

        for(int i = 0; i <= coins.size(); ++i)
            dp[0][i] = 1;

        for(int i = 0; i <= amount; ++i)
            for(int j = 1; j <= coins.size(); ++j) {
                
                dp[i][j] = dp[i][j-1];
                if(j - 1 >= 0 && i - coins[j-1] >= 0)
                    dp[i][j] += dp[i-coins[j-1]][j];
            }

        return dp[amount][coins.size()];
    }
};
