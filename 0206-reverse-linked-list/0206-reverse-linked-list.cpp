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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode();
        dummy->next = nullptr;
        ListNode *cur, *next;
        for (cur = head; cur != nullptr; cur = next) {
            next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
        }
        
        return dummy->next;
    }
};