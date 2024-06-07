/*

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
*/

vector<int> leftView(Node *root)
{
    // If the root is NULL, return an empty vector
    if (!root)
        return {};

    queue<Node *> q; // Queue for level-order traversal
    vector<int> ans; // Vector to store the left view

    q.push(root); // Start with the root node

    while (!q.empty())
    {
        int n = q.size(); // Number of nodes at the current level

        // Iterate over all nodes at the current level
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front(); // Get the front node in the queue
            q.pop();                // Remove it from the queue

            // If this is the first node of the current level, add it to the result
            if (i == 1)
                ans.push_back(temp->data);

            // Add the left child to the queue if it exists
            if (temp->left != NULL)
                q.push(temp->left);
            // Add the right child to the queue if it exists
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return ans; // Return the left view of the binary tree
}
