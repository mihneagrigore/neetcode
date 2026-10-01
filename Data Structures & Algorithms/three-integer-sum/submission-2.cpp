class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        set<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i) {
            int target = -1 * nums[i];
            
            int p1 = i+1, p2 = nums.size() - 1;
            while(p1 < nums.size() && p2 >= 0 && p1 < p2) {
                if(nums[p1] + nums[p2] == target) {
                    result.insert({nums[i], nums[p1], nums[p2]});
                    p1++;
                    p2--;
                }
                else if(nums[p1] + nums[p2] < target) 
                    p1++;
                    else 
                        p2--;
            }
        }

        vector<vector<int>> finalResult(result.begin(), result.end());
        return finalResult;
    }
};
