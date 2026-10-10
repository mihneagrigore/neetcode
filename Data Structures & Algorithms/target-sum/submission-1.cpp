class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> dp;
        
        dp[0] = 1;

        for(auto x : nums) {
            auto prev = dp;

            for(int i = 0; i <= sum; ++i) {
                dp[i] = 0;
                dp[-i] = 0;
            }

            for(int i = -sum; i <= sum; ++i) {
                if(x + i <= sum)
                    dp[x+i] += prev[i];

                if(i - x >= -sum)
                    dp[i-x] += prev[i];
            }
        }

        return dp[target];
    }
};
