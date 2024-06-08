/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Example 1:
Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9
Output:
4 2 1 5 6 3 8 7 9
Explanation:

*/
class Solution
{
public:
    // Function to find the vertical order traversal of a Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        // Initialize a queue to store pairs of Node* and its corresponding horizontal distance from the root.
        queue<pair<Node *, int>> q;
        // Vector to store the final result.
        vector<int> ans;
        // Map to store nodes at each horizontal distance. The key is the horizontal distance and the value is a vector of node values at that distance.
        map<int, vector<int>> mp;

        // If the root is NULL, return an empty vector.
        if (root == NULL)
            return ans;

        // Push the root node with a horizontal distance of 0 into the queue.
        q.push({root, 0});

        // Perform level order traversal.
        while (!q.empty())
        {
            // Get the front element of the queue.
            auto it = q.front();
            Node *temp = it.first; // Current node
            int val = it.second;   // Horizontal distance of the current node
            q.pop();

            // Insert the current node's value into the map at the corresponding horizontal distance.
            mp[val].push_back(temp->data);

            // If the current node has a left child, push it into the queue with a horizontal distance decremented by 1.
            if (temp->left)
                q.push({temp->left, val - 1});

            // If the current node has a right child, push it into the queue with a horizontal distance incremented by 1.
            if (temp->right)
                q.push({temp->right, val + 1});
        }

        // Traverse the map and collect all nodes' values in the final result vector.
        for (auto it : mp)
        {
            for (int i = 0; i < it.second.size(); i++)
            {
                ans.push_back(it.second[i]);
            }
        }

        // Return the result vector containing the vertical order traversal of the tree.
        return ans;
    }
};
