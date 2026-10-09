class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 1)
            return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        dp[1][0] = -min(prices[0], prices[1]);
        dp[1][1] = dp[0][0] + prices[1];

        int maxim = max(dp[0][0], max(dp[1][1], 0));

        for(int i = 2; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);

            maxim = max(maxim, max(dp[i][0], dp[i][1]));
        }

        return maxim;   
    }
};
