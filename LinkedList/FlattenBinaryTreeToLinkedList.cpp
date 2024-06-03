/*
Given the root of a binary tree, flatten the tree into a "linked list":
The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
Example 1:
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
*/

class Solution
{
public:
    // Helper function to flatten the binary tree and return the tail node of the flattened subtree
    TreeNode *flattn(TreeNode *root)
    {
        if (root == NULL)
            return NULL; // Base case: if the node is NULL, return NULL

        // Recursively flatten the left and right subtrees
        TreeNode *leftTail = flattn(root->left);   // Flatten the left subtree and get its tail
        TreeNode *rightTail = flattn(root->right); // Flatten the right subtree and get its tail

        // If both left and right tails are NULL, it means it's a leaf node, so return the root
        if (leftTail == NULL && rightTail == NULL)
            return root;

        // If there is a left subtree but no right subtree
        else if (leftTail != NULL && rightTail == NULL)
        {
            root->right = root->left; // Move the left subtree to the right
            root->left = NULL;        // Set the left child to NULL
            return leftTail;          // Return the tail of the left subtree
        }

        // If both left and right subtrees exist
        else if (leftTail != NULL && rightTail != NULL)
        {
            TreeNode *temp = root->right; // Temporarily store the original right subtree
            root->right = root->left;     // Move the left subtree to the right
            root->left = NULL;            // Set the left child to NULL
            leftTail->right = temp;       // Connect the tail of the left subtree to the original right subtree
            return rightTail;             // Return the tail of the right subtree
        }

        // If there's no left subtree but a right subtree exists (this condition is redundant but kept for clarity)
        else
        {
            return rightTail;
        }
    }

    // Public function to flatten the binary tree
    void flatten(TreeNode *root)
    {
        flattn(root); // Call the helper function to start the process from the root
    }
};
