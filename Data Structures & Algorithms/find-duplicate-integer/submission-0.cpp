class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s1 = 0, s2 = 0, f = 0;

        while(s1 < nums.size() && f < nums.size() && nums[f] < nums.size()) {
            s1 = nums[s1];
            f = nums[nums[f]];

            if(s1 == f)
                break;
        }

        if(f < nums.size()) {
            while(s1 != s2) {
                s1 = nums[s1];
                s2 = nums[s2];
            }
        }

        return s2;

    }
};
