/*
You are given a perfect binary tree where all leaves are on the same level,
and every parent has two children.
The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node.
If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Example 1:
Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A),
your function should populate each next pointer to point to its next right node,
just like in Figure B.
The serialized output is in level order as connected by the next pointers,
with '#' signifying the end of each level.
*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL; // If the tree is empty, return NULL

        Node *root1 = root; // Start with the root node

        // Traverse level by level until there are no more left children
        while (root1->left != NULL)
        {
            Node *temp = root1; // Temporary pointer to traverse the current level

            // Traverse nodes at the current level
            while (temp != NULL)
            {
                // Connect the left child to the right child of the same parent
                temp->left->next = temp->right;

                // If there is a next node at the same level, connect the right child to the left child of the next node
                if (temp->next != NULL)
                {
                    temp->right->next = temp->next->left;
                }

                temp = temp->next; // Move to the next node at the same level
            }

            root1 = root1->left; // Move to the next level by going to the leftmost node of the current level
        }

        return root; // Return the modified tree with next pointers set
    }
};
