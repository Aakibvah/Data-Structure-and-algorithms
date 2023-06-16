/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
Input: head = [1,2,2,1]
Output: true
Input: head = [1,2]
Output: false
Success
Details
Runtime: 231 ms, faster than 84.40% of C++ online submissions for Palindrome Linked List.
Memory Usage: 114.1 MB, less than 77.59% of C++ online submissions for Palindrome Linked List.
*/
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == NULL)
            return true;

        ListNode *first = head;
        ListNode *second;
        int count = 0;

        // counting numbers of node
        while (first)
        {
            count++;
            first = first->next;
        }
        first = head;

        count = (count + 1) / 2;
        while (--count)
        {
            first = first->next;
        }

        second = first->next;

        first->next = NULL;

        second = Reverse(second);
        first = head;
        while (second)
        {

            if (first->val == second->val)
            {

                first = first->next;
                second = second->next;
            }
            else
                return false;
        }

        return true;
    }

    ListNode *Reverse(ListNode *node)
    {

        if (node->next == NULL)
            return node;

        ListNode *prev = NULL;
        ListNode *curr = node;
        while (curr != NULL)
        {

            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};