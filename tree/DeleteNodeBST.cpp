/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
*/
class Solution
{
public:
    // Helper function to find the maximum value in a binary search tree (BST)
    int findMax(TreeNode *root)
    {
        // Traverse to the rightmost node, which holds the maximum value
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }

    // Main function to delete a node with a given key in a BST
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        // Base case: if the tree is empty, return NULL
        if (root == NULL)
            return NULL;

        // If the key to be deleted is smaller than the root's key, move to the left subtree
        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        // If the key to be deleted is greater than the root's key, move to the right subtree
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        // If the key is equal to the root's key, this is the node to be deleted
        else
        {
            // Case 1: Node with only one child or no child
            if (root->left == NULL && root->right == NULL)
            {
                return NULL; // No child
            }
            else if (root->left != NULL && root->right == NULL)
            {
                return root->left; // Only left child
            }
            else if (root->right != NULL && root->left == NULL)
            {
                return root->right; // Only right child
            }
            // Case 2: Node with two children
            else
            {
                // Find the maximum value in the left subtree
                int temp = findMax(root->left);

                // Replace the root's value with the maximum value from the left subtree
                root->val = temp;

                // Delete the node with the maximum value from the left subtree
                root->left = deleteNode(root->left, temp);

                // Return the root node after deletion
                return root;
            }
        }
        // Return the root node after performing the deletion
        return root;
    }
};
