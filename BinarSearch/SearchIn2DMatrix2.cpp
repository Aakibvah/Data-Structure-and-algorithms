/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
This matrix has the following properties:
    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

Example 1:
Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
*/
class Solution
{
public:
    // Function to search for a target value in a 2D matrix
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Initialize row and column indices
        int i = 0;                    // Row index
        int j = matrix[0].size() - 1; // Column index (starting from the last column)

        // Traverse the matrix
        while (i < matrix.size() && j >= 0)
        {
            // If current element equals the target, return true
            if (matrix[i][j] == target)
                return true;
            // If current element is greater than the target, move left in the matrix
            else if (matrix[i][j] > target)
            {
                j--; // Move left in the current row
            }
            // If current element is less than the target, move down in the matrix
            else
            {
                i++; // Move down to the next row
            }
        }

        // If target is not found in the matrix, return false
        return false;
