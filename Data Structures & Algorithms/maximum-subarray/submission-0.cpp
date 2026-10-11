class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int bestSum = -1, sum = 0;
        for(auto x : nums) {
            if(x + sum >= bestSum)
                bestSum = x + sum;

            sum += x;

            if(sum < 0)
                sum = 0;
        }

        return bestSum;
    }
};
