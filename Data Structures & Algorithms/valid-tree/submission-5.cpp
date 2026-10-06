class Solution {
public:

    struct Node {

        int val;
        vector<Node*> neigh;

        Node(): val(0) {};
        Node(int x): val(x) {};
    };

    bool dfs(Node *node, Node* parent, vector<int> &vis) {
        if(vis[node->val] == 1)
            return false;

        if(vis[node->val] == 2)
            return true;
        
        vis[node->val] = 1;

        for(auto x : node->neigh) {
            if(x == parent)
                continue;

            if(!dfs(x, node, vis)) {
                cout<<x->val<<" ";
                return false;
            }
        }

        vis[node->val] = 2;

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<Node*> graph(n);

        for(int i = 0; i < n; ++i)
            graph[i] = new Node(i);

        for(auto x : edges) {
            graph[x[0]]->neigh.push_back(graph[x[1]]);
            graph[x[1]]->neigh.push_back(graph[x[0]]);
        }

        vector<int> vis(n, 0);
        bool ok = dfs(graph[0], nullptr, vis);

        if(!ok)
            return false;

        for(int i = 0; i < n; ++i)
            if(vis[i] == 0)
                return false;

        return true;
    }
};
