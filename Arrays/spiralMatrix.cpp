/*
Given an m x n matrix, return all elements of the matrix in spiral order
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix
        int i = 0;                // Current row index
        int j = 0;                // Current column index
        int rsteps = n - 1;       // Remaining steps for rows
        int csteps = m - 1;       // Remaining steps for columns
        vector<int> spiralMatrix; // Result vector to store spiral order traversal

        // Iterate while there are remaining steps for both rows and columns
        while (rsteps >= 1 && csteps >= 1)
        {
            // Traverse right in the current row
            for (int k = 0; k < csteps; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                j++;
            }

            // Traverse down in the last column
            for (int k = 0; k < rsteps; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                i++;
            }

            // Traverse left in the last row
            for (int k = 0; k < csteps; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                j--;
            }

            // Traverse up in the first column
            for (int k = 0; k < rsteps; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                i--;
            }
            // Move to the next starting position
            i++;
            j++;
            rsteps -= 2; // Reduce remaining steps for rows by 2
            csteps -= 2; // Reduce remaining steps for columns by 2
        }

        // If there are remaining steps for rows but no steps for columns
        if (rsteps == 0)
        {
            // Traverse right in the last row
            for (int k = 0; k < csteps + 1; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                j++;
            }
        }
        // If there are remaining steps for columns but no steps for rows
        else if (csteps == 0)
        {
            // Traverse down in the last column
            for (int k = 0; k < rsteps + 1; k++)
            {
                spiralMatrix.push_back(matrix[i][j]);
                i++;
            }
        }
        return spiralMatrix; // Return the spiral order traversal vector
    }
};
