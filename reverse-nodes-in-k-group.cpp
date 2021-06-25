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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        
        ListNode *end = head;
        for (int i = 0; i < k; i++)
        {
            if (end != NULL)
                end = end->next;
            else
                return head;
        }
        
        ListNode *newHead = reverseK(head, end);
        
        head->next = reverseKGroup(end, k);
        
        return newHead;
    }
    
    ListNode* reverseK(ListNode* head, ListNode* end) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next = NULL;
        
        while (cur != end)
        {
            next = cur->next;
            cur->next = pre;
            
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
};
