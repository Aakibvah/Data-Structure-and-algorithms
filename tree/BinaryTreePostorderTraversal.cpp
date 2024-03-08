/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
*/

class Solution
{
public:
    // Function to perform postorder traversal of a binary tree
    vector<int> postorderTraversal(TreeNode *root)
    {
        // Vector to store the traversal result
        vector<int> result;
        // Call the recursive helper function for postorder traversal
        postTrav(root, result);
        return result; // Return the traversal result
    }

    // Recursive helper function for postorder traversal
    void postTrav(TreeNode *root, vector<int> &a)
    {
        // Base case: If the current node is null, return
        if (root == nullptr)
            return;

        // Recursive call on the left subtree
        postTrav(root->left, a);
        // Recursive call on the right subtree
        postTrav(root->right, a);

        // Process the current node: Add its value to the result vector
        a.push_back(root->val);
    }
};