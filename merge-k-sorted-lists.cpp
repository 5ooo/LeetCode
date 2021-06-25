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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *cur = NULL;
        ListNode *tmp = NULL;

        priority_queue<ListNode *, vector<ListNode *>, CmpNode> q;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                q.push(lists[i]);
        }

        while(q.size() != 0)
        {
            tmp = q.top();
            q.pop();

            if (head == NULL)
            {
                head = tmp;
                cur = tmp;
            }
            else
            {
                cur->next = tmp;
                cur = cur->next;
            }

            if (tmp->next != NULL)
                q.push(tmp->next);

        }

        return head;
    }

    class CmpNode
    {
    public:
        bool operator()(ListNode *x, ListNode *y)
        {
            return x->val > y->val;
        }
    };
};
