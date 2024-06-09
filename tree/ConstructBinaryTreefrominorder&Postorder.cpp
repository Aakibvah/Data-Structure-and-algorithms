/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
class Solution
{
public:
    // Recursive helper function to build the tree
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int s, int e, int &idx, unordered_map<int, int> &mp)
    {
        // Base case: if the start index is greater than the end index, return NULL
        if (s > e)
            return NULL;

        // Get the current root value from the postorder traversal using idx
        int rootVal = postorder[idx];
        // Get the index of the root value in the inorder traversal using the map
        int i = mp[rootVal];
        // Decrement idx to move to the next root value in the postorder traversal
        idx--;

        // Create a new TreeNode with the root value
        TreeNode *root = new TreeNode(rootVal);

        // Recursively build the right subtree first (postorder: left-right-root)
        root->right = solve(inorder, postorder, i + 1, e, idx, mp);

        // Recursively build the left subtree
        root->left = solve(inorder, postorder, s, i - 1, idx, mp);

        // Return the constructed tree
        return root;
    }

    // Main function to build the binary tree from inorder and postorder traversals
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();     // Get the size of the traversals
        int idx = n - 1;            // Initialize idx to the last index of postorder traversal
        unordered_map<int, int> mp; // Create a map to store the indices of inorder values

        // Populate the map with indices of inorder values
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }

        // Call the recursive solve function to build the tree and return its root
        return solve(inorder, postorder, 0, n - 1, idx, mp);
    }
};
