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


int main()
{
	Solution s;

	return 0;
}
