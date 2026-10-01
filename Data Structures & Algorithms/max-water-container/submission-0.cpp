class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0, p2 = heights.size() - 1;
        int maxVol = 0;
        while(p1 < heights.size() && p2 >= 0 && p1 < p2) {
            int vol = (p2 - p1) * min(heights[p1], heights[p2]);

            if(maxVol < vol)
                maxVol = vol;
            
            if(heights[p1] < heights[p2])
                p1++;
            else 
                p2--;
        }

        return maxVol;
    }
};
