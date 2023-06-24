#include <iostream>
#include <vector>
using namespace std;

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = (rows * cols) - 1;
        int mid;
        int col;
        int row;

        while (s <= e)
        {
            mid = e + (s - e) / 2;
            row = mid / cols;
            col = mid % cols;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};

// solution 2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lowRow = 0;
        int highRow = matrix.size() - 1;

        while (lowRow < highRow)
        {
            int mid = lowRow + (highRow - lowRow) / 2;
            if (matrix[mid][0] == target)
            {
                return true;
            }
            if (matrix[mid][0] < target && target < matrix[mid + 1][0])
            {
                lowRow = mid;
                break;
            }
            if (matrix[mid][0] < target)
            {
                lowRow = mid + 1;
            }
            else
            {
                highRow = mid - 1;
            }
        }

        int lowCol = 0;
        int highCol = matrix[0].size() - 1;

        while (lowCol <= highCol)
        {
            int mid = lowCol + (highCol - lowCol) / 2;
            if (matrix[lowRow][mid] == target)
            {
                return true;
            }
            if (matrix[lowRow][mid] < target)
            {
                lowCol = mid + 1;
            }
            else
            {
            }
            else
            {
                highCol = mid - 1;
            }
        }

        return false;
    }
};