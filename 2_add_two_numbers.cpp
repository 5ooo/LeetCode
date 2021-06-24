/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* pointer = result;
        while (l1 != NULL || l2 != NULL) 
        {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                carry += l2->val;
                l2 = l2->next;
            }

            pointer->next = new ListNode(carry%10);
            carry /= 10;
            pointer = pointer->next;
        }

        if (carry > 0) {//记得处理最后的进位。。。
            pointer->next = new ListNode(carry);
        }

        return result->next;
    }

};
