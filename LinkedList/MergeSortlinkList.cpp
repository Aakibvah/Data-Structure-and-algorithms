/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
*/
class Solution
{
private:
    // Function to merge two sorted linked lists
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // Creating a dummy node to facilitate merging
        Node *dNode = new Node(-1);
        Node *temp = dNode;

        // Merging the lists while both are non-empty
        while (head1 != NULL && head2 != NULL)
        {
            // Comparing values of nodes to merge them in sorted order
            if (head1->data < head2->data)
            {
                temp->next = head1;
                temp = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head2;
                temp = head2;
                head2 = head2->next;
            }
        }

        // Appending the remaining nodes of either list
        if (head1 != NULL)
            temp->next = head1;
        else
            temp->next = head2;

        // Returning the merged list
        return dNode->next;
    }

    // Function to find the middle node of a linked list
    Node *mid(Node *h)
    {
        Node *fast = h;
        Node *slow = h;

        // Using fast and slow pointers to find the middle
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Returning the middle node
        return slow;
    }

public:
    // Function to sort the given linked list using Merge Sort

    Node *mergeSort(Node *head)
    {
        // Base case: if list is empty or has only one element, it's already sorted
        if (head == NULL || head->next == NULL)
            return head;

        // Finding the middle of the list
        Node *m = mid(head);
        Node *head2 = m->next;
        m->next = NULL; // Breaking the list into two halves

        // Recursively sorting the two halves
        Node *left = mergeSort(head);
        Node *right = mergeSort(head2);

        // Merging the sorted halves
        Node *merge = sortedMerge(left, right);

        // Returning the merged and sorted list
        return merge;
    }
};
