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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        pre->next = head;

        for (int i = 0; i < m - 1; i++)
            pre = pre->next;
        
        ListNode *cur = pre->next;
                
        ListNode *next = NULL;
        
        for (int i = 0; i < n - m; i++)
        {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        
        return dummy->next;
    }
};
