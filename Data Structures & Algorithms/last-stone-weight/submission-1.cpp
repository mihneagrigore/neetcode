class Solution {

priority_queue<int> pq;

public:
    int lastStoneWeight(vector<int>& stones) {
        for(auto x : stones) {
            pq.push(x);
        }

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x != y) 
                pq.push(abs(x - y));
        }

        return (pq.size() == 0) ? 0 : pq.top();
    }
};
