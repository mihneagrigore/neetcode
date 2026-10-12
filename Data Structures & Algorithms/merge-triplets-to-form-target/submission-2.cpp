class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        int x, y, z;
        bool ok1, ok2, ok3;
        ok1 = ok2 = ok3 = false;

        for(auto &t : triplets) {
            x = t[0], y = t[1], z = t[2];

            if (x > target[0] || y > target[1] || z > target[2])
                continue;

            if(x == target[0]) {
                ok1 = true;
            }

            if(y == target[1]) {
                ok2 = true;
            }

            if(z == target[2]) {
                ok3 = true;
            }
        }

        return ok1 && ok2 && ok3;

    }
};
