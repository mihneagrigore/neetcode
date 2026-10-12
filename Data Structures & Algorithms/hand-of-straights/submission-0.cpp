class Solution {
public:

    int getMax(vector<int> &vec) {
        int maxim = -1;
        for(int i = 0; i < vec.size(); ++i)
            maxim = max(maxim, vec[i]);

        return maxim;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() == 0)
            return false;

        sort(hand.begin(), hand.end());

        vector<int> elems(getMax(hand) + 1, 0);

        for(auto x : hand)
            elems[x]++;

        for(int i = 0; i < hand.size(); ++i) {
            if(elems[hand[i]] == 0)
                continue;

            elems[hand[i]]--;

            for(int j = 1; j < groupSize; ++j)
                if(hand[i] + j >= elems.size() || elems[hand[i]+j] == 0)
                    return false;
                else
                    elems[hand[i]+j]--;
        }

        return true;
    }
};
