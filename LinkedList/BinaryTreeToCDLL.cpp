/*
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List (CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Example 1:

Input:
      1
    /   \
   3     2
Output:
3 1 2
2 1 3
Explanation: After converting tree to CDLL
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.
*/
class Solution
{
public:
    Node *head = NULL; // Pointer to the head of the list
    Node *prev = NULL; // Pointer to keep track of the previous node in the list

    // Function to convert binary tree into circular doubly linked list
    Node *bTreeToCList(Node *root)
    {
        if (root == NULL)
            return NULL; // Base case: if the node is NULL, return NULL

        // Recursively convert the left subtree
        bTreeToCList(root->left);

        // Process the current node
        if (prev == NULL)
        {
            head = root; // If prev is NULL, it means this is the head node
        }
        else
        {
            root->left = prev;  // Link the current node to the previous node
            prev->right = root; // Link the previous node to the current node
        }
        prev = root; // Update prev to the current node

        // Recursively convert the right subtree
        bTreeToCList(root->right);

        // After the entire tree is processed, link the head and tail to make it circular
        if (head != NULL && prev != NULL)
        {
            head->left = prev;  // Link the head's left to the tail (prev)
            prev->right = head; // Link the tail's right to the head
        }

        return head; // Return the head of the circular doubly linked list
    }
};
