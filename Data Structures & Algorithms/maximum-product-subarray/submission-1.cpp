class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());

        dp[0] = {nums[0], nums[0]};

        int maxRes = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int maxCurr = max({
                nums[i],
                nums[i] * dp[i - 1].first,
                nums[i] * dp[i - 1].second
            });

            int minCurr = min({
                nums[i],
                nums[i] * dp[i - 1].first,
                nums[i] * dp[i - 1].second
            });

            dp[i] = {maxCurr, minCurr};

            maxRes = max(maxRes, maxCurr);
        }

        return maxRes;
    }
};