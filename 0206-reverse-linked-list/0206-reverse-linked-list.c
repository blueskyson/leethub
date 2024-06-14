/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode ListNode;
    ListNode *cursor = head;
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = NULL;
    while (cursor != NULL) {
        ListNode *node = cursor;
        cursor = cursor->next;
        node->next = dummy->next;
        dummy->next = node;
    }
    
    return dummy->next;
}