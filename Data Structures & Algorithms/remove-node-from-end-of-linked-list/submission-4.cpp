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
class Solution
{
    ListNode *reverseLinkedList(ListNode *head)
    {
        ListNode *prv = nullptr;
        while (head)
        {
            ListNode *next = head->next;
            head->next = prv;
            prv = head;
            head = next;
        }
        return prv;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head) return nullptr;

        // Step 1: reverse the list
        ListNode *newHead = reverseLinkedList(head);

        // Step 2: traverse to the nth node in reversed list
        ListNode *pointer = newHead;
        ListNode *prv = nullptr;

        while (pointer && --n > 0) {
            prv = pointer;
            pointer = pointer->next;
        }

        // Step 3: delete the nth node
        if (!pointer) {
            // n was larger than length
            return reverseLinkedList(newHead);
        }

        if (prv == nullptr) {
            // remove the head of reversed list
            newHead = pointer->next;
        } else {
            prv->next = pointer->next;
        }

        // Step 4: reverse again
        return reverseLinkedList(newHead);
    }
};
