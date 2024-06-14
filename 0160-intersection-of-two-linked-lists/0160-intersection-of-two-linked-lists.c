/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    typedef struct ListNode ListNode;
    int length1 = 0, length2 = 0;
    ListNode *ptr1 = headA, *ptr2 = headB;
    while (ptr1 != NULL) {
        ptr1 = ptr1->next;
        length1++;
    }
    while (ptr2 != NULL) {
        ptr2 = ptr2->next;
        length2++;
    }
    
    ptr1 = headA;
    ptr2 = headB;
    if (length1 > length2) {
        int offset = length1 - length2;
        for (int i = 0; i < offset; i++) {
            ptr1 = ptr1->next;
        }
    } else if (length2 > length1) {
        int offset = length2 - length1;
        for (int i = 0; i < offset; i++) {
            ptr2 = ptr2->next;
        }
    }
    
    while (ptr1 != ptr2) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}