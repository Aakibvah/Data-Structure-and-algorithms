/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []

*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *first = head;
        ListNode *temp;
        int count = 0;

        if (head->next == NULL && n == 1)
        {
            return NULL;
        }
        while (first)
        {
            first = first->next;
            count++;
        }

        first = head;
        count = (count - n);
        if (count == 0)
        {
            head = head->next;
            return head;
        }

        while (--count)
            first = first->next;

        temp = first->next;
        first->next = temp->next;
        delete (temp);

        return head;
    }
};