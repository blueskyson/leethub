/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        
        ListNode *slow = head, *fast = head;
        while (true) {
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
            if (fast->next == nullptr) {
                break;
            }
            fast = fast->next;
            
            slow = slow->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};