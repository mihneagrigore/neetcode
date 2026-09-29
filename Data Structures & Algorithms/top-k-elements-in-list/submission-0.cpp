class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto v : nums) {
            count[v]++;
        }

        map<int, vector<int>, greater<int>> buckets;
        for (auto [num, freq] : count) {
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (auto& [key, value] : buckets) {
            while (!value.empty() && k) {
                int elem = value.back();
                value.pop_back();

                result.push_back(elem);
                k--;
            }
        }

        return result;
    }
};
