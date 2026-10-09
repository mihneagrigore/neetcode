class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> lcs(text1.size(), vector<int>(text2.size(), 0));

        if(text1[0] == text2[0])
            lcs[0][0] = 1;

        for(int i = 1; i < text1.size(); ++i)
            lcs[i][0] = lcs[i-1][0] || (text1[i] == text2[0]);

        for(int i = 1; i < text2.size(); ++i)
            lcs[0][i] = lcs[0][i-1] || (text2[i] == text1[0]);

        for(int i = 1; i < text1.size(); ++i)
            for(int j = 1; j < text2.size(); ++j)
                if(text1[i] == text2[j])
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                else
                    lcs[i][j] = max(lcs[i-1][j], max(lcs[i][j-1], 
                                                        lcs[i-1][j-1]));

        return lcs[text1.size() - 1][text2.size() - 1];
    }
};
