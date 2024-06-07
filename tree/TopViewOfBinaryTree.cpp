/*
Given below is a binary tree. The task is to print the top view of binary tree.
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.
 Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost).
For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer.
 Here 8 and 9 are on the same position but 9 will get shadowed.
Example 1:
Input:
      1
   /    \
  2      3
Output: 2 1 3
*/
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in a Binary Tree.
    vector<int> topView(Node *root)
    {
        // If the root is NULL, return an empty vector
        if (!root)
            return {};

        queue<pair<Node *, int>> q; // Queue for level-order traversal with horizontal distance
        vector<int> ans;            // Vector to store the top view
        map<int, int> mp;           // Map to store the first node at each horizontal distance

        q.push({root, 0}); // Start with the root node at horizontal distance 0

        while (!q.empty())
        {
            auto it = q.front();   // Get the front element in the queue
            Node *temp = it.first; // Node pointer
            int val = it.second;   // Horizontal distance
            q.pop();               // Remove the front element from the queue

            // If this horizontal distance is not yet in the map, add the node's data
            if (mp.find(val) == mp.end())
                mp[val] = temp->data;

            // Add the left child to the queue with horizontal distance -1
            if (temp->left != NULL)
                q.push({temp->left, val - 1});
            // Add the right child to the queue with horizontal distance +1
            if (temp->right != NULL)
                q.push({temp->right, val + 1});
        }

        // Collect the results from the map, which is sorted by horizontal distance
        for (auto it : mp)
            ans.push_back(it.second);

        return ans; // Return the top view of the binary tree
    }
};
