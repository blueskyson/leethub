/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode ListNode;
    ListNode *cur = head;
    int length = 0;
    while (cur != NULL) {
        length++;
        cur = cur->next;
    }
    
    int index = length - n;
    ListNode **indirect = &head;
    for (int i = 0; i < index; i++) {
        indirect = &(*indirect)->next;
    }
    
    *indirect = (*indirect)->next;
    return head;
}