class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, currentGas = 0, idx = 0;
        for(int i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];

            totalGas += diff;
            currentGas += diff;

            if(currentGas < 0) {
                idx = i+1;
                currentGas = 0;
            }
        }

        if(totalGas < 0)
            return -1;
        
        return idx;
    }
};
