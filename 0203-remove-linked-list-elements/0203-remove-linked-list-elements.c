/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    typedef struct ListNode ListNode;
    ListNode *dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode *current = head;
    while (current != NULL) {
        if (current->val == val) {
            if (current == head) {
                head = current->next;
            }
            dummy->next = current->next;
            current = current->next;
        } else {
            dummy = current;
            current = current->next;
        }
    }
    
    return head;
}