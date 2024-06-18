/*
Given a binary tree, find its height.

Example 1:

Input:
     1
    /  \
   2    3
Output: 2
*/
class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
    {
        // If the node is NULL, the height is 0 (base case)
        if (node == NULL)
            return 0;

        // Recursively calculate the height of the left subtree
        int leftSubTreeHeight = height(node->left);

        // Recursively calculate the height of the right subtree
        int rightSubTreeHeight = height(node->right);

        // The height of the current node is the maximum of the heights of
        // the left and right subtrees, plus 1 for the current node
        return max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }
};
