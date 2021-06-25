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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode *> sa;
        stack<ListNode *> sb;
        
        for (; headA != NULL; headA = headA->next)
            sa.push(headA);
        
        for (; headB != NULL; headB = headB->next)
            sb.push(headB);
        
        ListNode *ret = NULL;
        
        while (sa.size() != 0 && sb.size() != 0 && sa.top() == sb.top())
        {
            ret = sa.top();
            sa.pop();
            sb.pop();

        }
        
        return ret;
    }
};
