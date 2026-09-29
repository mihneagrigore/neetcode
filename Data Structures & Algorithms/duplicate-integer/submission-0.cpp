class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, bool> seen;

        for(auto v : nums) {
            if(seen.contains(v))
                return true;
            else
                seen.insert({v, true});
        }

        return false;
    }
};