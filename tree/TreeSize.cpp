/*
Given a binary tree of size n, you have to count the number of nodes in it. For example, the count of nodes in the tree below is 4.

        1
     /      \
   10      39
  /
5

Example 1:
Input:
1 2 3
Output:
3
*/
class Solution
{
public:
    // Function to get the size of the binary tree
    int getSize(Node *node)
    {
        // Base case: if the node is null, return 0
        if (node == NULL)
            return 0;

        // Recursively get the size of the left subtree
        int leftSize = getSize(node->left);
        // Recursively get the size of the right subtree
        int rightSize = getSize(node->right);

        // Return the total size, which is the sum of sizes of left and right subtrees plus 1 (for the current node)
        return leftSize + rightSize + 1;
    }
};