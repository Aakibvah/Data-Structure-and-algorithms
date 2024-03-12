/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
// recursive soln

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Base case: If either dimension is zero or negative, there are no valid paths
        if (m - 1 < 0 || n - 1 < 0)
            return 0;

        // Base case: If both dimensions are reduced to 1, there's only one unique path
        if (m - 1 == 0 && n - 1 == 0)
            return 1;

        // Recursive step: Move left and up to compute the number of unique paths
        int left = uniquePaths(m, n - 1); // Number of unique paths going left
        int up = uniquePaths(m - 1, n);   // Number of unique paths going up

        // Return the total number of unique paths, which is the sum of paths from left and up
        return left + up;
    }
};

// memoization soln
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Initialize a memoization array to store computed values
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Base cases:
        // If either dimension is zero or negative, there are no valid paths
        if (m - 1 < 0 || n - 1 < 0)
            return 0;

        // If both dimensions are reduced to 1, there's only one unique path
        if (m - 1 == 0 && n - 1 == 0)
            return 1;

        // If the value for current cell is already computed, return it
        if (dp[m - 1][n - 1] != -1)
            return dp[m - 1][n - 1];

        // Calculate the number of unique paths recursively by moving left and up
        int left = uniquePaths(m, n - 1); // Number of unique paths going left
        int up = uniquePaths(m - 1, n);   // Number of unique paths going up

        // Store the result in the memoization array
        dp[m - 1][n - 1] = left + up;

        // Return the total number of unique paths, which is the sum of paths from left and up
        return dp[m - 1][n - 1];
    }
};

// tabulation solm
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Initialize a memoization array with dimensions m x n, and fill it with 1's
        // Each cell represents the number of unique paths to reach that cell
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // Iterate over the grid, starting from the second row and second column
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // The number of unique paths to reach cell (i, j) is the sum of paths from its top and left cells
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the value stored in the bottom-right cell, representing the total number of unique paths
        return dp[m - 1][n - 1];
    }
};
