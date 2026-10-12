class Solution {
public:
    vector<int> partitionLabels(string s) {

        unordered_map<char, int> frecv;

        for(auto x : s)
            frecv[x] = frecv[x] + 1;

        int count = 0, letters = 0;
        unordered_set<char> inGroup;
        vector<int> result;
        for(int i = 0; i < s.size(); ++i) {
            if(!inGroup.contains(s[i])) {
                inGroup.insert(s[i]);
                letters += frecv[s[i]];

                letters--;
                count++;
            } else {
                letters--;
                frecv[s[i]]--;

                count++;
            }

            if(letters == 0) {
                inGroup.clear();
                result.push_back(count);

                count = 0;
            }
        }

        return result;
    }
};
