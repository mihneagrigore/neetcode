class KthLargest {

priority_queue<int, vector<int>, greater<int>> pq;
int target;

public:
    KthLargest(int k, vector<int>& nums) {

        target = k;

        for(auto x : nums) {
            if(pq.size() < k)
                pq.push(x);
            else
                if(pq.top() < x) {
                    pq.pop();
                    pq.push(x);
                }
        }
    }
    
    int add(int val) {
        if(pq.size() < target) {
            pq.push(val);
        } else {
            if(val > pq.top())
                pq.pop(), pq.push(val);
        }

        return pq.top();
    }
};
