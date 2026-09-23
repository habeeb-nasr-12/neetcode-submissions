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
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> nodesSeen;
        while (head)
        {
            if (nodesSeen.count(head))
                return true;

            nodesSeen.insert(head);
            head = head->next;
        }
        return false;
    }
};
