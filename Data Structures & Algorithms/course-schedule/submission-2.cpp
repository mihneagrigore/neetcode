class Solution {
public:

    struct Node {
        int val;
        vector<Node*> neighbors;

        Node() : val(0) {}
        Node(int x) : val(x) {}
    };

    bool dfs(Node* x, vector<int>& state) {
        if(state[x->val] == 1)
            return false;

        if(state[x->val] == 2)
            return true;

        state[x->val] = 1;

        for(auto p : x->neighbors) {
            if(!dfs(p, state))
                return false;
        }

        state[x->val] = 2;

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Node* graph[1001];

        for(int i = 0; i < numCourses; ++i)
            graph[i] = new Node(i);

        for(auto p : prerequisites)
            graph[p[0]]->neighbors.push_back(graph[p[1]]);

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; ++i) {
            if(state[i] == 0) {
                if(!dfs(graph[i], state))
                    return false;
            }
        }

        return true;
    }
};