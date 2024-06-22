/*
The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
The diagram below shows two trees each with diameter nine,
the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine,
but no path longer than nine nodes).
Example 1:

Input:
       1
     /  \
    2    3
Output: 3
*/
class Solution
{
    int dia = 0; // Variable to store the diameter of the tree

public:
    // Function to return the diameter of a Binary Tree.
    int helper(Node *root)
    {
        if (root == NULL)
            return -1; // Base case: if the node is null, return -1

        // Recursively calculate the height of the left subtree
        int leftTree = helper(root->left);

        // Recursively calculate the height of the right subtree
        int rightTree = helper(root->right);

        // Update the diameter if the sum of left and right heights + 2 is greater than the current diameter
        dia = max(dia, leftTree + rightTree + 2);

        // Return the height of the tree rooted at the current node
        return max(leftTree, rightTree) + 1;
    }

    int diameter(Node *root)
    {
        // Initialize the helper function to calculate the diameter
        helper(root);
        return dia + 1; // Return the final diameter of the tree
    }
};
