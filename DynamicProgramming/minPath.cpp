/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/
// memoization soln

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        // Get the number of rows and columns in the grid
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize a memoization array with dimensions rows x cols
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        // Call the helper function to calculate the minimum path sum recursively
        int ans = helper(grid, dp, rows - 1, cols - 1);

        // Return the minimum path sum
        return ans;
    }

    // Helper function to calculate the minimum path sum recursively
    int helper(vector<vector<int>> &grid, vector<vector<int>> &dp, int rows, int cols)
    {
        // Base case: If either rows or cols becomes negative, return maximum integer value
        if (rows < 0 || cols < 0)
            return INT_MAX;

        // Base case: If we reach the top-left cell, return its value
        if (rows == 0 && cols == 0)
            return grid[0][0];

        // If the value for current cell is already computed, return it
        if (dp[rows][cols] != -1)
            return dp[rows][cols];

        // Calculate the minimum path sum recursively by considering up and left moves
        int up = helper(grid, dp, rows - 1, cols);
        int left = helper(grid, dp, rows, cols - 1);

        // Update the memoization array with the minimum path sum for current cell
        dp[rows][cols] = grid[rows][cols] + min(up, left);

        // Return the minimum path sum for current cell
        return dp[rows][cols];
    }
};

// tabulation soln
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        // Initialize a memoization array with dimensions rows x cols
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == 0 && j == 0)
                    // Base case: top-left cell, the path sum is the value of the cell itself
                    dp[i][j] = grid[i][j];
                else
                {
                    // Calculate the minimum path sum for current cell based on the values of its top and left cells
                    // If i or j is at the border, adjust the values accordingly to avoid out-of-bounds access
                    int up = grid[i][j] + ((i > 0) ? dp[i - 1][j] : INT_MAX);   // Add the value of the current cell to the path sum from the top cell
                    int left = grid[i][j] + ((j > 0) ? dp[i][j - 1] : INT_MAX); // Add the value of the current cell to the path sum from the left cell

                    // Store the minimum path sum for current cell in the memoization array
                    dp[i][j] = min(left, up);
                }
            }
        }

        // Return the minimum path sum for the bottom-right cell
        return dp[rows - 1][cols - 1];
    }
};