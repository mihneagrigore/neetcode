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

    void remove(ListNode *head, ListNode *prev, ListNode* &headMain, int &n) {
        if(head == nullptr)
            return;

        remove(head->next, head, headMain, n);

        n--;

        if(n == 0) {
            if(prev == nullptr) {
                headMain = head->next;
                return;
            }

            prev->next = head->next;
            return;
        }

    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || (head->next == nullptr && n >= 1))
            return nullptr;

        remove(head, nullptr, head, n);

        return head;
    }
};
