/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
*/

int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *temp1 = head1;
    Node *temp2 = head2;
    if (head1 == NULL || head2 == NULL)
        return -1;
    // Loop until the intersection point is found or both pointers reach the end
    while (temp1 && temp2)
    {
        // If the pointers meet, it means an intersection point is found
        if (temp1 == temp2)
            return temp1->data; // Return the data value of the intersection point
        // Move both pointers one step forward
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == NULL && temp2 == NULL)
            return -1;
        // If any pointer reaches the end, move it to the head of the other list
        if (temp1 == nullptr)
            temp1 = head2;
        if (temp2 == nullptr)
            temp2 = head1;
    }
}
