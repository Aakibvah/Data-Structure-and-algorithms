/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
*/
class Solution
{
public:
    // Depth First Search (DFS) function for Topological Sorting
    void dfs(int node, vector<int> adj[], int vis[], stack<int> &st)
    {
        vis[node] = 1; // Mark the current node as visited

        // Traverse all adjacent nodes of the current node
        for (auto it : adj[node])
        {
            if (!vis[it])
            {                          // If the adjacent node is not visited
                dfs(it, adj, vis, st); // Recursively call DFS on the adjacent node
            }
        }

        st.push(node); // Push the current node to the stack after visiting all its adjacent nodes
    }

    // Function to return list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0}; // Array to track visited nodes, initialized to 0 (not visited)
        stack<int> st;    // Stack to store the topological order

        // Perform DFS to create the topological order
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {                         // If the node is not visited
                dfs(i, adj, vis, st); // Perform DFS starting from the current node
            }
        }

        vector<int> ans; // Vector to store the topological order

        // Extract elements from the stack to get the topological order
        while (!st.empty())
        {
            ans.push_back(st.top()); // Add the top element of the stack to the topological order
            st.pop();                // Remove the top element from the stack
        }

        return ans; // Return the topological order
    }
};
s