class Solution {
public:

    struct Node {
        int val;
        vector<Node*> neighbors;

        Node() : val(0) {}
        Node(int x) : val(x) {}
    };

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Node* graph[1001];
        int indeg[1001] = {0};

        for(int i = 0; i < numCourses; ++i)
            graph[i] = new Node(i);

        for(auto p : prerequisites) {
            graph[p[0]]->neighbors.push_back(graph[p[1]]);
            indeg[p[1]]++;
        }

        queue<int> result;
        queue<int> q;

        for(int i = 0; i < numCourses; ++i) 
            if(indeg[i] == 0) {
                q.push(i);
            }

        while(!q.empty()) {
            int top = q.front();
            q.pop();

            result.push(top);

            for(auto x : graph[top]->neighbors) {
                indeg[x->val]--;
                if(indeg[x->val] == 0)
                    q.push(x->val);
            }
        }

        vector<int> finalRes;
        if(result.size() != numCourses)
            return finalRes;

        while(!result.empty()) {
            finalRes.insert(finalRes.begin(), result.front());

            result.pop();
        }

        return finalRes;
    }
};
