/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr)
            return nullptr;

        Node* corresp[101] = {nullptr};
        vector<int> visited;
        queue<Node*> pq;

        Node *first = new Node(node->val);

        pq.push(node);
        visited.push_back(node->val);
        corresp[first->val] = first;

        while(!pq.empty()) {
            Node *curr = pq.front();
            pq.pop();

            for(auto x : curr->neighbors) {

                if(corresp[x->val] == nullptr) {
                    Node *aux = new Node(x->val);

                    corresp[curr->val]->neighbors.push_back(aux);
                    corresp[x->val] = aux;

                } else {
                    Node *aux = corresp[x->val];
                    corresp[curr->val]->neighbors.push_back(aux);
                }

                if(find(visited.begin(), visited.end(), x->val) == visited.end()) {
                    pq.push(x);
                    visited.push_back(x->val);
                }
            }
        }
        
        return first;
    }
};
