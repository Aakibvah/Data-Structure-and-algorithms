/*
There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.
You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on.
Even if the same lamp is listed more than once, it is turned on.
When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.
You are also given another 2D array queries, where queries[j] = [rowj, colj].
For the jth query, determine whether grid[rowj][colj] is illuminated or not.
After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist.
A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].
Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated,
or 0 if the lamp was not.

Example 1:
Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off.
In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1.
Then, we turn off all lamps in the red square.
The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0.
Then, we turn off all lamps in the red rectangle.
*/
#include <vector>
#include <map>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        // Maps to store counts of lamps in rows, columns, and diagonals
        map<int, int> m1Row;
        map<int, int> m2Col;
        map<int, int> diagnol1;
        map<int, int> diagnol2;
        // Map to store the position of lamps as a 1D long long integer
        map<long long, int> lampPosIn1D;

        // Initialize the maps with the lamp positions
        for (int i = 0; i < lamps.size(); i++)
        {
            int row = lamps[i][0];
            int col = lamps[i][1];
            long long pos = (long long)row * n + col;
            m1Row[row]++;
            m2Col[col]++;
            diagnol1[row - col]++;
            diagnol2[row + col]++;
            lampPosIn1D[pos]++;
        }

        // Vector to store the results of the queries
        vector<int> ans(queries.size());
        // Possible directions to check around the queried cell
        vector<vector<int>> directions = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0}};

        // Process each query
        for (int i = 0; i < queries.size(); i++)
        {
            int row = queries[i][0];
            int col = queries[i][1];
            long long pos = (long long)row * n + col;

            // Check if the queried cell is illuminated
            if (m1Row[row] > 0 || m2Col[col] > 0 || diagnol1[row - col] > 0 || diagnol2[row + col] > 0 || lampPosIn1D[pos] > 0)
                ans[i] = 1;
            else
                ans[i] = 0;

            // Turn off the lamp and all adjacent lamps
            for (int d = 0; d < directions.size(); d++)
            {
                int row1 = row + directions[d][0];
                int col1 = col + directions[d][1];
                long long pos1 = (long long)row1 * n + col1;

                // Check if the adjacent position is valid and has a lamp
                if (row1 >= 0 && col1 >= 0 && row1 < n && col1 < n && lampPosIn1D.find(pos1) != lampPosIn1D.end())
                {
                    int times = lampPosIn1D[pos1];

                    // Decrease the counts in the maps for the turned-off lamp
                    m1Row[row1] -= times;
                    m2Col[col1] -= times;
                    diagnol1[row1 - col1] -= times;
                    diagnol2[row1 + col1] -= times;
                    lampPosIn1D.erase(pos1); // Remove the lamp from the map
                }
            }
        }
        return ans; // Return the results of the queries
    }
};
