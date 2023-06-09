/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Runtime: 11 ms, faster than 71.51% of C++ online submissions for Linked List Cycle.
Memory Usage: 7.9 MB, less than 96.00% of C++ online submissions for Linked List Cycle.
*/
// soln

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {

        if (head == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            if (slow == fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};