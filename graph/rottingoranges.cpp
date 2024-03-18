/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
*/
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> q; // Queue to store coordinates of oranges and time taken to rot
        int n = grid.size();                // Number of rows in the grid
        int m = grid[0].size();             // Number of columns in the grid

        int vis[n][m];    // 2D array to track visited oranges
        int time = 0;     // Time taken for all oranges to rot
        int cntfresh = 0; // Count of fresh oranges

        // Initialize visited array and count fresh oranges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0}); // Push coordinates of rotten orange and time 0
                    vis[i][j] = 2;       // Mark as visited
                }
                else
                {
                    vis[i][j] = 0; // Mark as not visited
                }
                if (grid[i][j] == 1)
                    cntfresh++; // Count fresh oranges
            }
        }

        int row[] = {-1, 0, 1, 0}; // Directions: up, right, down, left
        int col[] = {0, 1, 0, -1};

        int cnt = 0; // Count of oranges that have rotted

        // BFS to simulate rotting process
        while (!q.empty())
        {
            int r = q.front().first.first;  // Current orange row
            int c = q.front().first.second; // Current orange column
            int t = q.front().second;       // Time taken for this orange to rot
            q.pop();                        // Remove front element from the queue
            time = max(time, t);            // Update time

            // Explore neighbors of current orange
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + row[i]; // Neighbor row
                int ncol = c + col[i]; // Neighbor column

                // Check if neighbor is within grid bounds and is a fresh orange
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1}); // Push neighbor coordinates and increment time
                    vis[nrow][ncol] = 2;           // Mark neighbor as visited
                    cnt++;                         // Increment count of rotted oranges
                }
            }
        }

        // If all fresh oranges have rotted, return time; otherwise, return -1
        if (cnt != cntfresh)
            return -1;

        return time; // Return time taken for all oranges to rot
    }
};
