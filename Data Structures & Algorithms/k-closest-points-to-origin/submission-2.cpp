class Solution {

struct Point {
    int x, y;

    bool operator>(const Point& other) const {
        if (x != other.x)
            return x > other.x;
        return y > other.y;
    }

    bool operator<(const Point& other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
};

int euclidianDist(Point a, Point b) 
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

priority_queue<pair<int, Point>> pq;

Point origin = {0, 0};

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto p : points) {
            Point aux;
            aux.x = p[0];
            aux.y = p[1];

            if(pq.size() < k)
                pq.push({euclidianDist(aux, origin), aux});
            else if(pq.top().first > euclidianDist(aux, origin)) {
                pq.pop();
                pq.push({euclidianDist(aux, origin), aux});
            }
        }

        vector<vector<int>> result;
        while(!pq.empty()) {
            Point curr = pq.top().second;
            pq.pop();

            result.push_back({curr.x, curr.y});
        }

        return result;
    }
};
