/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode *prev = dummy;
    while (prev->next != NULL) {
        ListNode *first = prev->next;
        ListNode *second = first->next;
        if (second != NULL) {
            prev->next = second;
            first->next = second->next;
            second->next = first;
        }
        prev = first;
    }
    
    return dummy->next;
}