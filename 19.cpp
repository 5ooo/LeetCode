#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *pHead = new ListNode(0);
        pHead->next = head;

        ListNode *pCur = pHead;
		ListNode *pEnd = pHead;

		for (int i = 0; i < n + 1; i++)
		{
            if (pEnd == NULL)
                return head;

            pEnd = pEnd->next;
		}
		
		while(pEnd != NULL)
		{
			pEnd = pEnd->next;
			pCur = pCur->next;
		}
        
        ListNode *pDel = pCur->next;

		pCur->next = pCur->next->next;

        delete pDel;

        ListNode *pRet = pHead->next;

        delete pHead;

		return pRet;
    }
};


int main()
{
	Solution s;

	return 0;
}
