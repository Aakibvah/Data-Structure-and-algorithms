/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        vector<int> list;
        ListNode *first = list1;
        ListNode *second = list2;

        if (list1 == NULL && list2 == NULL)
            return list1;

        while (first && second)
        {
            if (first->val < second->val)
            {
                list.push_back(first->val);
                first = first->next;
            }
            else
            {
                list.push_back(second->val);
                second = second->next;
            }
        }
        while (first)
        {
            list.push_back(first->val);
            first = first->next;
        }
        while (second)
        {
            list.push_back(second->val);
            second = second->next;
        }

        ListNode *head = new ListNode;
        head->val = list[0];
        ListNode *temp;
        temp = head;
        for (int i = 1; i < list.size(); i++)
        {
            temp->next = new ListNode;
            temp = temp->next;
            temp->val = list[i];
        }

        return head;
    }
};