/*
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
*/
class Solution
{
public:
    // Depth First Search (DFS) function to traverse the graph
    void dfs(vector<int> adjLS[], int node, int vis[])
    {
        vis[node] = 1; // Mark the current node as visited

        // Traverse all adjacent nodes of the current node
        for (auto it : adjLS[node])
        {
            if (!vis[it])
            {                        // If the adjacent node is not visited
                dfs(adjLS, it, vis); // Recursively call DFS on the adjacent node
            }
        }
    }

    // Function to find the number of provinces in the graph
    int numProvinces(vector<vector<int>> &adj, int V)
    {
        int cnt = 0;          // Counter for the number of provinces
        vector<int> adgLS[V]; // Adjacency list representation of the graph
        int vis[V] = {0};     // Array to track visited nodes, initialized to 0 (not visited)

        // Create adjacency list from the adjacency matrix
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {                          // If there is an edge between nodes i and j
                    adgLS[i].push_back(j); // Add j to the adjacency list of i
                    adgLS[j].push_back(i); // Add i to the adjacency list of j (for undirected graph)
                }
            }
        }

        // Perform DFS to find connected components (provinces)
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {                       // If the node is not visited
                cnt++;              // Increment the province count
                dfs(adgLS, i, vis); // Perform DFS starting from the current node
            }
        }

        return cnt; // Return the number of provinces
    }
};
