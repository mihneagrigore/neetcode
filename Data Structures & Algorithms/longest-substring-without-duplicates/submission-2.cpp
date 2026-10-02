class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.size() == 0)
            return 0;

        if(s.size() == 1 || (s.size() == 2 && s[0] == s[1]))
            return 1;
        
        int p1 = 0, p2 = 0;

        set<int> found;
        found.insert(s[p1]);

        int maxDist = 1;
        while(p1 < s.size() && p2+1 < s.size()) {

            p2++;
            if(found.contains(s[p2])) {
                while(s[p1] != s[p2]) {
                    found.erase(s[p1]);
                    p1++;
                }
                found.erase(s[p1]);
                p1++;
            }

            found.insert(s[p2]);

            if(maxDist < p2 - p1 + 1) {
                maxDist = p2 - p1 + 1;
                // cout<< p2 <<" "<<p1<<endl;
            }
        }

        return maxDist;
    }
};
