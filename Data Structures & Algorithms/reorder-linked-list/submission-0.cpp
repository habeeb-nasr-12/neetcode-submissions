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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prv = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prv;
            prv = head;
            head = next;
        }
        return prv;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // Step 1: Find the middle of the list using slow and fast pointers
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        ListNode* secondHalf = slow->next;
        slow->next = nullptr; // Terminate the first half

        // Step 2: Reverse the second half
        secondHalf = reverseLinkedList(secondHalf);

        // Step 3: Merge the two halves alternately
        ListNode* firstHalf = head;
        while (secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};