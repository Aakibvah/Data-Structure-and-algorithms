/*
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node.
If such a node does not exist, return null.

Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
*/

class Solution
{
public:
    // Function to search for a node with a given value in a Binary Search Tree (BST)
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // Iterate until root is NULL (end of tree) or the value is found
        while (root != NULL)
        {
            // If the current node's value matches the search value, return the node
            if (root->val == val)
                return root;

            // If the current node's value is greater than the search value,
            // move to the left subtree
            if (root->val > val)
                root = root->left;
            // If the current node's value is less than the search value,
            // move to the right subtree
            else if (root->val < val)
                root = root->right;
        }
        // If the value is not found, return NULL
        return NULL;
    }
};
