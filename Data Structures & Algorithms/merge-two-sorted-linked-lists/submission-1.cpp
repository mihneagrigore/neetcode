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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *result = nullptr;
        ListNode *finalResult = result;

        if(list1 == nullptr && list2 == nullptr)
            return nullptr;

        if(list1 == nullptr) {
            result = finalResult = list2;
            list2 = list2->next;
            goto SKIP;
        }

        if(list2 == nullptr) {
            result = finalResult = list1;
            list1 = list1->next;
            goto SKIP;
        }

        if(list1->val < list2->val) {
            result = list1;
            finalResult = result;
            list1 = list1->next;
        } else {
            result = list2;
            finalResult = result;
            list2 = list2->next;
        }

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                ListNode *aux  = list1;
                list1 = list1->next;

                result->next = aux;
                result = result->next;
            } else {
                ListNode *aux = list2;
                list2 = list2->next;

                result->next = aux;
                result = result -> next;
            }
        }

SKIP:
        while(list1 != nullptr) {
            result->next = list1;
            list1 = list1->next;
            result = result->next;
        }

        while(list2 != nullptr) {
            result->next = list2;
            list2 = list2->next;
            result = result->next;
        }

        return finalResult;
    }
};
