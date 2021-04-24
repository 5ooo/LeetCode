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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *pHead = new ListNode(0);
        ListNode *pCur  = pHead;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                pCur->next = l2;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                pCur->next = l1;
                l1 = l1->next;
            }
            else
            {
                if (l1->val > l2->val)
                {
                    pCur->next = l2;
                    l2 = l2->next;
                }
                else
                {
                    pCur->next = l1;
                    l1 = l1->next;
                }
            }
            pCur = pCur->next;
        }

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
