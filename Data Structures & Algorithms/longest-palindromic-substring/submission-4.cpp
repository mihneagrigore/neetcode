class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if(ans.size() < r - l + 1)
                    ans = s.substr(l, r-l+1);

                l--;
                r++;
            }

            // Even-length palindromes
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if(ans.size() < r - l + 1)
                    ans = s.substr(l, r-l+1);
                
                l--;
                r++;
            }
        }

        return ans;
    }
};
