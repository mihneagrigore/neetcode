class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];

        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> nums1, nums2;

        nums1.push_back(nums[0]);

        for(int i = 1; i < nums.size() - 1; ++i) {
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i]);
        }

        nums2.push_back(nums[nums.size() - 1]);

        // nums1
        int dp1[101] = {0};
        dp1[0] = nums1[0];
        dp1[1] = max(nums1[0], nums1[1]);
        for(int i = 2; i < nums1.size(); ++i)
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums1[i]);

        // num2
        int dp2[101] = {0};
        dp2[0] = nums2[0];
        dp2[1] = max(nums2[0], nums2[1]);
        for(int i = 2; i < nums2.size(); ++i)
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums2[i]);
        
        return max(dp1[nums1.size() - 1], dp2[nums2.size() - 1]);
    }
};
