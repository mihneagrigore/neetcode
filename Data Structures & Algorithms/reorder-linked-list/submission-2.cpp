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

    ListNode* reorder(ListNode* &node, ListNode* prev) {
        if(node->next == nullptr) {
            node->next = prev;
            return node;
        }

        ListNode *last = reorder(node->next, node);

        node->next = prev;

        return last;
    }

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;

        ListNode *slow = head, *fast = head, *p = head;

        while(fast != nullptr && fast->next != nullptr && slow != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        fast = reorder(second, slow);

        while(p != fast && p -> next != fast) {
            ListNode *aux = p->next, *fastaux = fast; 
            p->next = fast;
            fast = fast->next;
            p = aux;
            fastaux->next = aux;
        }
    }
};
