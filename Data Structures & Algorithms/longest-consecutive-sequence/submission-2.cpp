class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        set<int> values;

        for (auto x : nums) 
            values.insert(x);
    
        int first = *values.begin();
        values.erase(values.begin());

        int k = 1, max = 1;
        for (auto x : values) {
            if(x == first + 1)
                k++;
            else
                k = 1;
            
            if(k > max)
                max = k;
            
            first = x;
        }

        return max;
    }
};
