class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {};

        for (char c : tasks)
            freq[c - 'A']++;

        sort(freq, freq + 26, greater<int>());

        int maxFreq = freq[0];
        int intervals = (maxFreq - 1) * (n + 1) + 1;

        int i = 1;
        while (i < 26 && freq[i] == maxFreq) {
            intervals++;
            i++;
        }

        return max((int)tasks.size(), intervals);
    }
};