/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    typedef struct ListNode ListNode;
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode *index1 = head, *index2 = fast;
            while (index1 != index2) {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index1;
        }
    }
    
    return NULL;
}