/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []

*/
class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // Vector to store the level order traversal result
        vector<vector<int>> result;
        // Call the helper function to perform the level order traversal
        traverse(root, result);
        return result;
    }

    // Helper function for level order traversal
    void traverse(TreeNode *root, vector<vector<int>> &a)
    {
        // Queue to store nodes for level order traversal
        queue<TreeNode *> q;
        // Temporary vector to store values at each level
        vector<int> temp1;

        // Base case: If the root is null, return
        if (root == nullptr)
            return;

        // Push the root node into the queue
        q.push(root);

        // Perform level order traversal using a queue
        while (!q.empty())
        {
            // Get the number of nodes at the current level
            int n = q.size();

            // Traverse all nodes at the current level
            for (int i = 0; i < n; i++)
            {
                // Get the front node from the queue
                TreeNode *temp = q.front();
                q.pop();
                // Add the value of the front node to the temporary vector
                temp1.push_back(temp->val);
                // If the left child of the front node exists, push it into the queue
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                // If the right child of the front node exists, push it into the queue
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            // Add the temporary vector containing values at the current level to the result vector
            a.push_back(temp1);
            // Clear the temporary vector for the next level
            temp1.clear();
        }
    }
};