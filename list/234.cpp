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


int main()
{
	Solution s;

	return 0;
}
