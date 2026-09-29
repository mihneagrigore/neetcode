class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, bool> isNumber;
        for(auto v : nums)
            isNumber.insert({v, true});

        for(auto v : nums)
            if(isNumber[target - v]) {
                int pos1 = find(nums.begin(), nums.end(), v) - nums.begin();
                for(int i = 0; i < nums.size(); ++i)
                    if(v + nums[i] == target && pos1 != i)
                        return {pos1, i};
            }
    }
};
