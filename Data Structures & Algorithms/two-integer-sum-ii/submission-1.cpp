class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int p1 = 0, p2 = numbers.size() - 1;

        while(p1 < p2 && p1 < numbers.size() && p2 >= 0) {
            if(numbers[p1] + numbers[p2] == target)
                return {p1 + 1, p2 + 1};
            else if(numbers[p1] + numbers[p2] < target)
                p1++;
                else
                    p2--;
        }

        return {};
    }
};
