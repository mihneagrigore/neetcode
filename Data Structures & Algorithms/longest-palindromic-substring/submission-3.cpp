class Solution {
public:
    string longestPalindrome(string s) {

        if(s.size() == 1)
            return s;
        
        if(s.size() == 2) {
            if(s[0] == s[1])
                return s;
            else
                return s.substr(0, 1);
        }

        int maxLeft = 0, maxRight = 0;
        if(s[0] == s[1])
            maxRight = 1;

        for(int i = 1; i < s.size() - 1; ++i) {
            // check odd case
            int left = i, right = i;
            while(s[left] == s[right]) {
                left--;
                right++;

                if(left < 0 || right > s.size() - 1)
                    break;
            }

            left++;
            right--;

            if(right - left > maxRight - maxLeft) {
                maxRight = right;
                maxLeft = left;
            }

            // check even case
            left = i;
            right = i+1;
            while(s[left] == s[right]) {
                left--;
                right++;

                if(left < 0 || right > s.size() - 1)
                    break;
            }

            left++;
            right--;

            if(right - left > maxRight - maxLeft) {
                maxRight = right;
                maxLeft = left;
            }

            cout<<maxLeft<<" "<<maxRight<<endl;
        }

        return s.substr(maxLeft, maxRight - maxLeft +1);
    }
};
