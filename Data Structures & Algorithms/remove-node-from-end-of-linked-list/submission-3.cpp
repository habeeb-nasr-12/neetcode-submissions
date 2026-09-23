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
        if (!head)
            return nullptr;

        ListNode *newHead = reverseLinkedList(head);
        ListNode *pointer = newHead;
        ListNode *prv = nullptr;

        while (pointer && n > 0)
        {
            ListNode *next = pointer->next;
            if (n == 1)
            {
                if (prv != nullptr)
                    prv->next = next;
               else 
                 newHead = pointer->next;

                break;
            }
            n--;
            prv = pointer;
            pointer = next;
        }

        ListNode *res = reverseLinkedList(newHead);
        return res;
    }
};
