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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* sorted = new ListNode();
        sorted->val = head->val;
        sorted->next = nullptr;
        head = head->next;
        while (head != nullptr){
            ListNode* start = sorted;
            ListNode* prv = nullptr;
            while (start != nullptr && start->val < head->val){
                prv = start;
                start = start->next;
            }
           
            ListNode* nxt = head->next;
            if (prv == nullptr){
                head->next = sorted;
                sorted = head;
            }else {
                prv->next = head;
                head->next = start;
            }
            head = nxt;
        }
        return sorted;
    }
};