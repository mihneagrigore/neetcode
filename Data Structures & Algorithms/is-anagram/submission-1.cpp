class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagram_s, anagram_t;

        for(auto ch : s) 
            anagram_s[ch]++;

        for(auto ch : t) 
            anagram_t[ch]++;

        for(auto [key, value] : anagram_s) 
            if(value != anagram_t[key])
                return false;

        for(auto [key, value] : anagram_t) 
            if(value != anagram_s[key])
                return false;

        return true;
    }
};
