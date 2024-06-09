/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree
 and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/
class Solution
{
public:
    // Helper function to construct the tree.
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int s, int e, int &idx, unordered_map<int, int> &mp)
    {
        // Base case: if the start index is greater than the end index, return NULL.
        if (s > e)
            return NULL;

        // Get the root value from preorder traversal using the current index.
        int rootVal = preorder[idx];
        // Find the index of the root value in the inorder traversal using the hashmap.
        int i = mp[rootVal];
        // Increment the current index for preorder traversal.
        idx++;

        // Create the root node with the root value.
        TreeNode *root = new TreeNode(rootVal);
        // Recursively construct the left subtree.
        root->left = solve(preorder, inorder, s, i - 1, idx, mp);
        // Recursively construct the right subtree.
        root->right = solve(preorder, inorder, i + 1, e, idx, mp);
        // Return the constructed root node.
        return root;
    }

    // Main function to build the tree.
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int idx = 0;             // Initialize the index for preorder traversal.
        int n = preorder.size(); // Get the number of nodes.

        // Create a hashmap to store the indices of inorder values for quick access.
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }

        // Call the helper function to construct the tree and return the root.
        return solve(preorder, inorder, 0, n - 1, idx, mp);
    }
};
