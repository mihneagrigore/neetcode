#include <limits.h>

#define INF INT_MAX

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto x : times) {
            graph[x[0]].push_back({x[1], x[2]});
        }

        vector<int> dist(n+1, INF);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            int currDist = pq.top().first, currNode = pq.top().second;
            pq.pop();

            if(currDist > dist[currNode])
                continue;

            for(auto neigh : graph[currNode]) {
                int p = neigh.first, w = neigh.second;

                if(dist[currNode] + w < dist[p]) {
                    dist[p] = dist[currNode] + w;
                    pq.push({dist[p], p});
                }
            }
        }
        
        int max = -1;
        for(int i = 1; i <= n; ++i) {
            if(i == k)
                continue;

            if(dist[i] == INF)
                return -1;

            if(max < dist[i])
                max = dist[i];
        }
        
        return max;
    }
};
