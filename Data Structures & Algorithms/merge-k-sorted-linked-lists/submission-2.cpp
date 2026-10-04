/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    struct Compare {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *result = new ListNode(-1);
        ListNode *copy = result;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(int i = 0; i < lists.size(); ++i)
            if(lists[i] != nullptr)
                pq.push(lists[i]);

        while(!pq.empty()) {
            ListNode *minimum = pq.top();
            pq.pop();

            result->next = minimum;
            minimum = minimum->next;
            result = result->next;

            if(minimum != nullptr)
                pq.push(minimum);
        }

        return copy->next;
    }
};
