class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxProf = 0, minCurr = 101;

        for(auto x : prices) {
            if(minCurr > x)
                minCurr = x;

            if(maxProf < x - minCurr)
                maxProf = x - minCurr;
        }

        return maxProf;
    }
};
