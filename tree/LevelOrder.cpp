/*
Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

Input:
    1
  /   \
 3     2
Output:
1 3 2

*/
class Solution
{
public:
    // Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node *root)
    {
        // Vector to store the level order traversal result
        vector<int> result;
        // Call the helper function to perform the level order traversal
        helper(root, result);
        return result;
    }

    // Helper function for level order traversal
    void helper(Node *root, vector<int> &ans)
    {
        // Base case: If the root is null, return
        if (root == nullptr)
            return;

        // Create a queue to store nodes for level order traversal
        queue<Node *> q;
        // Push the root node into the queue
        q.push(root);

        // Perform level order traversal using a queue
        while (!q.empty())
        {
            // Get the front node from the queue
            Node *fr = q.front();
            // Add the value of the front node to the result vector
            ans.push_back(fr->data);
            // Remove the front node from the queue
            q.pop();

            // If the left child of the front node exists, push it into the queue
            if (fr->left != nullptr)
            {
                q.push(fr->left);
            }
            // If the right child of the front node exists, push it into the queue
            if (fr->right != nullptr)
            {
                q.push(fr->right);
            }
        }
    }
};