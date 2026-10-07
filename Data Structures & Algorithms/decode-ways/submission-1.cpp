class Solution {
public:
    int numDecodings(string s) {

        if(s.size() == 0)
            return 0;

        if(s[0] == '0')
            return 0;

        int dp[101][2] = {0};
        dp[0][0] = 1;

        for(int i = 1; i < s.size(); ++i) {

            if(s[i] != '0')
                dp[i][0] = dp[i-1][1] + dp[i-1][0];

            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] - '0' <= 6))
                dp[i][1] = dp[i-1][0];
            else
                dp[i][1] = 0;
        }

        return dp[s.size()-1][1] + dp[s.size()-1][0];
    }
};
