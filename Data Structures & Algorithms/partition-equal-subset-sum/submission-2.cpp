
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<bool> sums(target + 1, false);
        sums[0] = true;

        for (int x : nums) {
            for (int j = target; j >= x; --j) {
                sums[j] = sums[j] || sums[j - x];
            }
        }

        return sums[target];
    }
};
