class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 1)
            return 1;

        if(s.size() == 2) {
            if(s[0] == s[1])
                return 3;
            else
                return 2;
        }

        int substr = 0;

        for(int i = 0; i < s.size(); ++i) {

            // Odd length palindrome
            int left = i, right = i;

            while(left >= 0 && right < s.size() &&
                  s[left] == s[right]) {
                left--;
                right++;

                substr++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;

            while(left >= 0 && right < s.size() &&
                  s[left] == s[right]) {
                left--;
                right++;

                substr++;
            }

            left++;
            right--;
        }

        return substr;
    }
};
