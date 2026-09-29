#include <cstring>

class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(auto s : strs) {
            result += to_string(s.size());
            result += '.';
            result += s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        for(int i = 0; i < s.size(); ++i) {
            string len;
            while(i < s.size() && isdigit(s[i]) && s[i] != '.') {
                len += s[i++];
            }

            int nextLen = stoi(len);
            string current;
            for(int j = 0; j < nextLen && i < s.size(); ++j) {
                i++;
                current+=s[i];
            }

            result.push_back(current);
        }

        return result;
    }
};
