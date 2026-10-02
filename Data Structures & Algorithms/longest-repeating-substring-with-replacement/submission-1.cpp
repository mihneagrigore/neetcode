class Solution {
public:

    static bool cmp(pair<char, int> x, pair<char, int> y) {
        return x.second < y.second;
    }

    int characterReplacement(string s, int k) {
        int maxLen = 0;
        int p1 = 0, p2 = 0;

        unordered_map<char, int> freq;

        priority_queue<
            pair<char, int>,
            vector<pair<char, int>>,
            decltype(&cmp)
        > pq(cmp);

        while (p2 < s.size()) {

            freq[s[p2]]++;

            while (!pq.empty())
                pq.pop();

            for (auto x : freq)
                pq.push({x.first, x.second});

            int maxFreq = pq.top().second;

            while ((p2 - p1 + 1) - maxFreq > k) {
                freq[s[p1]]--;
                p1++;

                while (!pq.empty())
                    pq.pop();

                for (auto x : freq)
                    pq.push({x.first, x.second});

                maxFreq = pq.top().second;
            }

            maxLen = max(maxLen, p2 - p1 + 1);

            p2++;
        }

        return maxLen;
    }
};