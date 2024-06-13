/*
Given the root of a Binary Search Tree (BST),
convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
*/
class Solution
{
public:
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        calc(root, sum);    // Calculate the sum of all nodes
        inorder(root, sum); // Convert BST to GST
        return root;
    }

    // Calculate the sum of all nodes in the tree
    void calc(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return; // Base case: If the node is null, return

        calc(root->left, sum); // Traverse the left subtree

        sum = sum + root->val; // Add the current node's value to sum

        calc(root->right, sum); // Traverse the right subtree

        return;
    }

    // Traverse the tree in inorder and update each node to make it GST
    void inorder(TreeNode *root, int &sum)
    {
        if (root == NULL)
            return; // Base case: If the node is null, return

        inorder(root->left, sum); // Traverse the left subtree

        int temp = root->val; // Store the current node's value in temp
        root->val = sum;      // Update the current node's value to sum
        sum = sum - temp;     // Subtract the original value of the node from sum

        inorder(root->right, sum); // Traverse the right subtree

        return;
    }
};
