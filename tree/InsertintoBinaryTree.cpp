/*
You are given the root node of a binary search tree (BST) and
 a value to insert into the tree. Return the root node of the BST after the insertion.
 It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST
after insertion. You can return any of them.

Example 1:
Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
*/
class Solution
{
public:
    // Function to insert a value into a Binary Search Tree (BST)
    TreeNode *insertIntoBST(TreeNode *root1, int val)
    {
        // Create a new TreeNode with the given value
        TreeNode *temp = new TreeNode(val);

        // If the tree is empty, return the new node as the root
        if (root1 == NULL)
            return temp;

        // Start from the root of the tree
        TreeNode *root = root1;

        // Loop to find the correct position to insert the new node
        while (true)
        {
            // If the current node's value is greater than the new value
            if (root->val > val)
            {
                // If the left child is NULL, insert the new node here
                if (root->left == NULL)
                {
                    root->left = temp;
                    return root1; // Return the original root
                }
                else
                {
                    // Otherwise, move to the left child and continue
                    root = root->left;
                }
            }
            else
            {
                // If the current node's value is less than or equal to the new value
                // If the right child is NULL, insert the new node here
                if (root->right == NULL)
                {
                    root->right = temp;
                    return root1; // Return the original root
                }
                else
                {
                    // Otherwise, move to the right child and continue
                    root = root->right;
                }
            }
        }
    }
};
