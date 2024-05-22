/*
Given a doubly linked list and a position. The task is to delete a node from given position (position starts from 1) in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4
x = 3
Output: 1 3
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
*/
class Solution
{
public:
    Node *deleteNode(Node *head_ref, int x)
    {
        // Check if the list is empty
        if (head_ref == NULL)
            return NULL;

        int i = 1;
        Node *temp = head_ref;
        Node *temp1 = NULL; // Initialize temp1 to NULL
        Node *temp2 = NULL; // Initialize temp2 to NULL

        // If x is 1, delete the head node
        if (x == 1)
        {
            head_ref = head_ref->next; // Update head_ref to the next node
            delete temp;               // Delete the original head node
            return head_ref;
        }

        // Traverse the list until the x-th node
        while (i < x)
        {
            temp = temp->next;
            i++;
        }

        // Set temp1 to the previous node, if it exists
        if (temp->prev != NULL)
            temp1 = temp->prev;

        // Set temp2 to the next node, if it exists
        if (temp->next != NULL)
            temp2 = temp->next;

        // Update pointers to bypass the node to be deleted
        if (temp1)
            temp1->next = temp2;
        if (temp2)
            temp2->prev = temp1;

        delete temp; // Delete the node at position x

        return head_ref; // Return the updated head of the list
    }
};
