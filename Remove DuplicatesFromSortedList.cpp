/*
Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

Success
Runtime: 18 ms, faster than 8.35% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 11.5 MB, less than 67.77% of C++ online submissions for Remove Duplicates from Sorted List.
*/
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL)
            return head;
        ListNode *first = head;
        ListNode *second = head->next;

        while (second)
        {
            if (first->val == second->val)
            {
                first->next = second->next;
                second->next = NULL;
                delete (second);
                second = first->next;
            }
            else
            {
                first = first->next;
                second = first->next;
            }
        }

        return head;
    }
};