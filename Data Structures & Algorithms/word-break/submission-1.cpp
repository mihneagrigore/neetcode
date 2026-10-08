class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true;

        for(int i = s.size() - 1; i >= 0; --i) {
            for(auto str : wordDict) {
                if(i + str.size() <= s.size() && s.substr(i, str.size()) == str) 
                    dp[i] = dp[i] || dp[i + str.size()];
            }
        }

        return dp[0];
    }
};
