class Solution {

priority_queue<int, vector<int>, greater<int>> pq;

public:
    int findKthLargest(vector<int>& nums, int k) {
        for(auto x : nums) {
            if(pq.size() < k)
                pq.push(x);
            else 
                if(x >= pq.top()) 
                    pq.pop(), pq.push(x);
        }

        return pq.top();
    }
};
