/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *current = head, *prev = head;
    while (current != NULL) {
        if (current->val == val) {
            if (current == head) {
                head = head->next;
                current = head;
                prev = head;
            } else {
                prev->next = current->next;
                current = current->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return head;
}
