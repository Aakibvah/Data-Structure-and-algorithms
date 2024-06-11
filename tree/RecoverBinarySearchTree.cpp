/*
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake.
Recover the tree without changing its structure.

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
*/

class Solution
{
public:
    // Pointers to keep track of the two nodes to be swapped
    TreeNode *f, *s, *prev;

    // Function to recover the tree
    void recoverTree(TreeNode *root)
    {
        // Initialize pointers
        f = s = prev = NULL;
        // Perform inorder traversal to find the two nodes
        inorder(root);
        // Swap the values of the two nodes to correct the tree
        swap(f->val, s->val);
    }

    // Helper function to perform inorder traversal
    void inorder(TreeNode *curr)
    {
        // Base case: if the current node is NULL, return
        if (curr == NULL)
            return;

        // Traverse the left subtree
        inorder(curr->left);

        // Check if the current node breaks the BST property
        if (prev != NULL && prev->val > curr->val)
        {
            // If this is the first violation, mark the first and second nodes
            if (f == NULL)
            {
                f = prev;
                s = curr;
            }
            else
            {
                // If this is the second violation, update the second node
                s = curr;
            }
        }
        // Update the previous node
        prev = curr;

        // Traverse the right subtree
        inorder(curr->right);
    }
};
