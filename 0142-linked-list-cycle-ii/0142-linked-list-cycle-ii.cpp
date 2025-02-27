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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr; // If list is empty or has only one node, no cycle

        ListNode *slow = head, *fast = head;

        // Detect cycle using Floyd’s algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                slow = head; // Reset slow pointer to head
                while (slow != fast) { // Move both one step at a time
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Start of the cycle
            }
        }
        return nullptr; // No cycle found
    }
};
