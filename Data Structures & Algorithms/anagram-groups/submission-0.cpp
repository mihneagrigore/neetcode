class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> result;

        for(auto word : strs) {
            vector<int> freq;
            freq.resize(26, 0); 
            for(auto ch : word)
                freq[ch - 'a']++;

            result[freq].push_back(word);
        }

        vector<vector<string>> output;
        for(auto [key, value] : result)
            output.push_back(value);

        return output;
    }
};
