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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        // Continue as long as there are nodes to process or a leftover carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Extract values, using 0 if the pointer has reached the end (nullptr)
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Compute the total sum and the new carry
            int total = val1 + val2 + carry;
            carry = total / 10;

            // Create a new node with the single digit and attach it to the result list
            current->next = new ListNode(total % 10);
            
            // Advance the result pointer
            current = current->next;

            // Advance the input pointers if they haven't reached the end
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Store the actual head of the result
        ListNode* result = dummyHead->next;
        delete dummyHead; 
        
        return result;  
    }
};