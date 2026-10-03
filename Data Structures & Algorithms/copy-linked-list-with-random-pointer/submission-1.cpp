/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == nullptr)
            return nullptr;

        map<Node*, Node*> transform;

        Node* start = new Node(head->val);
        Node *copy = start;
        transform.insert({head, start});
        while(head != nullptr) {
            if(head->next == nullptr)
                start->next = nullptr;
            else if(transform.find(head->next) != transform.end()) {
                start->next = transform[head->next];
            } else {
                Node *nxt = new Node(head->next->val);
                start->next = nxt; 
                transform.insert({head->next, nxt});
            }

            if(head->random == nullptr)
                start->random = nullptr;
            else if(transform.find(head->random) != transform.end()) {
                    start->random = transform[head->random];
                } else {
                    Node *rnd = new Node(head->random->val);
                    start->random = rnd;
                    transform.insert({head->random, rnd});
                }

            head = head->next;
            start = start->next;
        }

        return copy;
    }
};
