class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() == 1)
            return 0;

        int i = 0;
        int result = 0;

        while(i <= nums.size() - 1) {
            
            if(i + nums[i] >= nums.size() - 1) {
                result++;
                break;
            }

            int maxDist = -1, id;
            for(int j = 1; j <= nums[i]; ++j) {
                if(maxDist < i + j + nums[i+j]) {
                    maxDist = i + j + nums[i+j];
                    id = i + j;
                }
            }

                i = id;
                result++;
        }

        return result;
    }
};
