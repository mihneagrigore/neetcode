class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        
        for(auto x : coins)
            for(int i = 0; i <= amount; ++i)
                if(i + x <= amount)
                    dp[i+x] += dp[i];
        
        return dp[amount];
    }
};
