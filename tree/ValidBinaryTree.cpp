/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true
*/

class Solution
{
public:
    // Function to check if a binary tree is a valid Binary Search Tree (BST)
    bool isValidBST(TreeNode *root)
    {
        // Call the helper function with initial min and max values
        return isBST(root, LONG_MIN, LONG_MAX);
    }

    // Helper function to validate the BST property
    bool isBST(TreeNode *root, long min, long max)
    {
        // Base case: if the current node is NULL, it's a valid BST
        if (root == NULL)
            return true;

        // Check if the current node's value is within the valid range
        if (root->val <= min || root->val >= max)
            return false;

        // Recursively check the left subtree with updated max value
        bool left = isBST(root->left, min, root->val);
        // Recursively check the right subtree with updated min value
        bool right = isBST(root->right, root->val, max);

        // If either subtree is not a valid BST, return false
        if (!left || !right)
            return false;

        // If both subtrees are valid, return true
        return true;
    }
};
