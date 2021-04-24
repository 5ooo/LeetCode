#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <utility>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode *start = head;
        ListNode *end = head->next->next;
        
        ListNode *newhead = swapK(start, end);
        
        start->next = swapPairs(end);
        
        return newhead;
    }
    
    ListNode* swapK(ListNode* head, ListNode* end) {
        ListNode *pre, *cur, *next;
        
        pre = NULL;
        cur = head;
        
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


int main()
{
	Solution s;

	return 0;
}
