/*
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


Example 1:

Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

Output: 0 2 4 3 1
Explanation:
0 is connected to 2, 3, 1.
1 is connected to 0.
2 is connected to 0 and 4.
3 is connected to 0.
4 is connected to 2.
so starting from 0, it will go to 2 then 4,
and then 3 and 1.
Thus dfs will be 0 2 4 3 1.
Example 2:

Input: V = 4, adj = [[1,3], [2,0],
*/
class Solution
{
public:
    // Recursive DFS function to traverse the graph
    void dfs(vector<int> adj[], vector<int> &ans, int vis[], int s)
    {
        vis[s] = 1;       // Mark the current vertex as visited
        ans.push_back(s); // Add the current vertex to the result list

        // Traverse all adjacent vertices of the current vertex
        for (auto it : adj[s])
        {
            if (!vis[it])
            {                           // If the adjacent vertex is not visited
                dfs(adj, ans, vis, it); // Recursively call DFS on the adjacent vertex
            }
        }
    }

    // Function to perform DFS traversal of the graph
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;  // Vector to store the DFS traversal result
        int vis[V] = {0}; // Array to track visited vertices, initialized to 0 (not visited)
        int start = 0;    // Start DFS traversal from vertex 0

        dfs(adj, ans, vis, start); // Perform DFS traversal starting from vertex 0

        return ans; // Return the DFS traversal result
    }
};
