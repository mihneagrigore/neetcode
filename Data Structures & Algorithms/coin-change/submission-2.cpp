#include <limits.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        vector<int> dp(amount + 1, INT_MAX);

        for(auto x : coins)
            if(x <= amount)
                dp[x] = 1;

        for(auto x : coins) {
            for(int i = 1; i + x <= amount; ++i) {
                if(dp[i] != INT_MAX)
                    dp[i + x] = min(dp[i] + 1, dp[i+x]);  
            }

            for(int i = 1; i <= amount; ++i)
                cout<<dp[i]<<" ";
            cout<<endl;
        }

        if(dp[amount] == INT_MAX)
            return -1;
            
        return dp[amount];
    }
};
