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
    int getSize(ListNode* head)
    {
        int sz = 0;
        while(head)
            sz++, head = head->next->next;
        return sz;
    }
    int pairSum(ListNode* head) {
        int sz = getSize(head);
        ListNode* prv = nullptr;
        while(sz--)
        {
            ListNode* nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        int mx = 0;
        while(prv && head)
        {
            mx = max(mx, prv->val + head->val);
            head = head->next;
            prv = prv->next;
        }
        return mx;
    }
};