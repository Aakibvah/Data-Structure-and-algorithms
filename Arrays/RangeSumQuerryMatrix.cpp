/*
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and
lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix
inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
Example 1:
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
*/

#include <vector>
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> pfMat; // Prefix sum matrix

    NumMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();                             // Number of rows in the input matrix
        int m = matrix[0].size();                          // Number of columns in the input matrix
        pfMat = vector<vector<int>>(n, vector<int>(m, 0)); // Initialize prefix sum matrix with zeros

        // Compute prefix sum for each row
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                    pfMat[i][j] = matrix[i][j]; // First element of the row
                else
                    pfMat[i][j] = pfMat[i][j - 1] + matrix[i][j]; // Sum of previous element and current element
            }
        }

        // Compute prefix sum for each column
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                pfMat[i][j] = pfMat[i - 1][j] + pfMat[i][j]; // Sum of previous row element and current row element
            }
        }
    }

    // Method to compute sum of elements in a specified region
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = pfMat[row2][col2]; // Sum of elements in the bottom-right corner of the region
        if (row1 - 1 >= 0)
            sum -= pfMat[row1 - 1][col2]; // Remove sum of elements above the region
        if (col1 - 1 >= 0)
            sum -= pfMat[row2][col1 - 1]; // Remove sum of elements left to the region
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
            sum += pfMat[row1 - 1][col1 - 1]; // Add back overlapping sum

        return sum;
    }
};
