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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = nullptr;
        ListNode* start = nullptr;
        
        ListNode* prv = nullptr;
        ListNode* temp = head;
        ListNode* large = nullptr;
        while (temp != nullptr){
            if (temp->val < x){
                if (start == nullptr){
                    start = temp;
                    less = temp;
                }else {
                    less->next = temp;
                    less = less->next;
                }
                if (prv != nullptr){
                    prv->next = temp->next;
                }
                temp = temp->next;
            }else {
                if (large == nullptr) 
                    large = temp;
                prv = temp;
                temp = temp->next;
            } 
        }
        if (start == nullptr)
            return head;
        less->next = large;
        return start;
    }
};