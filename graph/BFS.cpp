/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v.
 Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph.
 Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
Example 1:

Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}


Output:
0 1 2 3 4
Explanation:
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3. After this 2 to 4, thus bfs will be
0 1 2 3 4.
*/
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Initialize an empty vector to store the BFS traversal result.
        vector<int> ans;
        // Initialize a queue for BFS traversal.
        queue<int> q;
        // Initialize a boolean array to keep track of visited nodes.
        bool vis[V] = {false};

        // Start BFS traversal from vertex 0.
        q.push(0);
        vis[0] = true;
        ans.push_back(0);

        // BFS traversal loop
        while (!q.empty())
        {
            // Dequeue a node from the queue.
            int node = q.front();
            q.pop();

            // Traverse adjacent nodes of the dequeued node.
            for (int i = 0; i < adj[node].size(); i++)
            {
                // Check if the adjacent node is not visited.
                if (!vis[adj[node][i]])
                {
                    // Mark the adjacent node as visited.
                    vis[adj[node][i]] = true;
                    // Enqueue the adjacent node for further traversal.
                    q.push(adj[node][i]);
                    // Add the adjacent node to the BFS traversal result.
                    ans.push_back(adj[node][i]);
                }
            }
        }
        // Return the BFS traversal result.
        return ans;
    }
};
