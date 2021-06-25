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
    bool isPalindrome(ListNode* head) {
        stack<ListNode *> s;
        
        ListNode *p = head;
        for (; p != NULL; p = p->next)
            s.push(p);
        
        int len = s.size() / 2;
        p = head;
        for (int i = 0; i < len; i++)
        {
            if (p->val != s.top()->val)
                return false;
            
            p = p->next;
            s.pop();
        }
        
        return true;
    }
};
