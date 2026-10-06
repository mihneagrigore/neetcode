class Solution {
public:

    struct Node {

        int val;
        vector<Node*> neigh;

        Node(): val(0) {};
        Node(int x): val(x) {};
    };

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<Node*> graph(n);

        for(int i = 0; i < n; ++i)
            graph[i] = new Node(i);

        for(auto x : edges) {
            graph[x[0]]->neigh.push_back(graph[x[1]]);
            graph[x[1]]->neigh.push_back(graph[x[0]]);
        }

        vector<int> vis(n, 0);
        int comp = 0;

        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                comp++;

                queue<Node*> q;
                q.push(graph[i]);
                vis[i] = 1;

                while(!q.empty()) {
                    Node *top = q.front();
                    q.pop();
                    vis[top->val] = 1;

                    for(auto x : top->neigh) {
                        if(!vis[x->val])
                            q.push(x);
                    }
                }
            }
        }

        return comp;

    }
};
