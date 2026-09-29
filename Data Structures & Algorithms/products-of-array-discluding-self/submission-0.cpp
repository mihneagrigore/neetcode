class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;

        vector<int> posZero;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0)
                posZero.push_back(i);
            else 
                p *= nums[i];
        }

        vector<int> result;

        if(posZero.size() > 1) {
            result.resize(nums.size(), 0);
            return result;
        }

        if(posZero.size() == 0) 
            for(int i = 0; i < nums.size(); ++i)
                result.push_back(p / nums[i]);
        else 
            for(int i = 0; i < nums.size(); ++i) 
                if(posZero[0] == i)
                    result.push_back(p);
                else 
                    result.push_back(0);
                    
        return result;
    }
};
