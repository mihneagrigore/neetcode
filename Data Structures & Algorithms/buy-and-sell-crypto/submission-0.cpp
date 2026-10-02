class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = 101, profit = 0;

        for(auto p : prices) {
            if(minPrice > p)
                minPrice = p;
            
            if(profit < p - minPrice)
                profit = p - minPrice;

            // cout<<minPrice<<" "<<profit<<endl;
        }

        return profit;
    }
};
