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
/// optimal soln
// Function to merge two sorted linked lists.
Node *sortedMerge(Node *head1, Node *head2)
{
    // Create a new node to serve as the dummy node for the merged list.
    // Initialize its data to -1. This node will be used to simplify the merging process.
    Node *dNode = new Node(-1);
    // Create a pointer 'temp' to traverse the merged list, initially pointing to the dummy node.
    Node *temp = dNode;

    // Traverse both input linked lists until either one becomes empty.
    while (head1 != NULL && head2 != NULL)
    {
        // Compare the data of the current nodes of both lists.
        if (head1->data < head2->data)
        {
            // If the data in head1 is smaller, connect the current node to temp and move head1 to its next node.
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            // If the data in head2 is smaller or equal, connect the current node to temp and move head2 to its next node.
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    // Connect the remaining nodes of the non-empty list to the merged list.
    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;

    // Return the next node of the dummy node, which is the starting node of the merged list.
    return dNode->next;
}
