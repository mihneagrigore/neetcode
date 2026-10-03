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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *finalResult = result;

        int tr = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val;

            if(tr) {
                sum++;
                tr = 0;
            }

            if(sum >= 10) {
                sum = sum % 10;
                tr = 1;
            }

            result->val = sum;

            if(l1->next != nullptr && l2->next != nullptr) {
                result->next = new ListNode();
                result = result->next;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr) {
            result->next = new ListNode();
            result = result->next;

            int sum = result->val + l1->val;

            if(tr) {
                sum++;
                tr = 0;
            } 

            if(sum >= 10) {
                sum = sum % 10;
                tr = 1;
            }    

            result->val = sum;

            l1 = l1->next;
        }

        while(l2 != nullptr) {
            result->next = new ListNode();
            result = result->next;

            int sum = result->val + l2->val;

            if(tr) {
                sum++;
                tr = 0;
            } 

            if(sum >= 10) {
                sum = sum % 10;
                tr = 1;
            }    

            result->val = sum;

            l2 = l2->next;
        }

        if(tr) {
            result->next = new ListNode(1);
        }

        return finalResult;

    }
};
