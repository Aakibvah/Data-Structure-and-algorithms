/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Runtime: 27 ms, faster than 50.16% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 14.9 MB, less than 65.12% of C++ online submissions for Remove Linked List Elements.
Next challenges:
*/
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *current = new ListNode;
        current->next = head;

        ListNode *temp = current;
        while (temp->next)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
                temp = temp->next;
        }
        ListNode *newh = current->next;

        return newh;
    }
};