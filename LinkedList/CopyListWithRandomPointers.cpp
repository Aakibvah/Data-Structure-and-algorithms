/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y,
then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.
Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL; // If the input list is empty, return NULL

        Node *temp1 = head;       // Pointer to traverse the original list
        Node *temp2 = head->next; // Pointer to keep track of next node in the original list

        // First pass: Create a copy of each node and insert it between current and next node of original list
        while (temp1 != NULL)
        {
            Node *dNode = new Node(temp1->val); // Create a new node with the same value as current node
            temp2 = temp1->next;                // Update temp2 to point to the next node in the original list
            temp1->next = dNode;                // Insert the new node between current and next node of original list
            dNode->next = temp2;                // Connect the new node to the next node in the original list
            temp1 = temp2;                      // Move temp1 to the next node in the original list
        }

        // Second pass: Assign random pointers for the copied nodes
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->random != NULL)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Third pass: Separate the original and copied lists
        Node *head2 = head->next; // head2 points to the head of the copied list
        Node *t1 = head;          // Pointer to traverse the original list
        Node *t2 = head2;         // Pointer to traverse the copied list

        while (t1 != NULL)
        {
            Node *t1p1 = t1->next->next;                           // Pointer to the next node in the original list
            Node *t2p2 = t2->next != NULL ? t2->next->next : NULL; // Pointer to the next node in the copied list

            t1->next = t1p1; // Disconnect the copied node from the original list
            t2->next = t2p2; // Disconnect the original node from the copied list

            t1 = t1p1; // Move t1 to the next node in the original list
            t2 = t2p2; // Move t2 to the next node in the copied list
        }
        return head2; // Return the head of the copied list
    }
};
