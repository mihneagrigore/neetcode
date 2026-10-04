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

    ListNode *ans = nullptr;

    ListNode* reverseK(ListNode *prev, ListNode *start, ListNode *curr, ListNode* nextRev, ListNode* &lastNext, int n, int k) {

        if(curr == nullptr && n <= k)
            return nullptr;

        if(n == k) {
            if(prev != nullptr) 
                prev->next = curr;
            else
                ans = curr;

            lastNext = curr->next;
            curr->next = nextRev;

            return start;
        }

        ListNode *result = reverseK(prev, start, curr->next, curr, lastNext, n+1, k);

        if(result == nullptr)
            return nullptr;

        if(n == 1)
            curr->next = lastNext;
        else 
            curr->next = nextRev;

        return result;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k == 0 || k == 1)
            return head;
        
        ListNode *curr = head, *prev = nullptr;
        ans = head;

        while(true) {
            ListNode *lastN = nullptr;

            curr = reverseK(prev, curr, curr, nullptr, lastN, 1, k);

            if(curr == nullptr)
                break;

            prev = curr;
            curr = curr->next;
        }

        return ans;
    }
};
