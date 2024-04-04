/*
Given a square matrix of N*N, print the outer boundary in clockwise direction
Input Format

First line contains an integer n representing size of matrix.
Each of next n lines contain n integer representing array elements.
Constraints

1 <= N <= 100
1 <= arr[i] <= 10^4
Output Format

Print the outer boundary in clockwise direction in a line with space in between each.
Sample Input 0

3
1 2 3
4 5 6
7 8 9
Sample Output 0
1 2 3 6 9 8 7 4
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n; // Read the size of the matrix

    int arr[n][n];
    // Input elements of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int i = 0;
    int j = 0;

    // Print elements in the first row from left to right
    for (int k = 0; k < n - 1; k++)
    {
        cout << arr[i][j] << " ";
        j++;
    }

    // Print elements in the last column from top to bottom
    for (int k = 0; k < n - 1; k++)
    {
        cout << arr[i][j] << " ";
        i++;
    }

    // Print elements in the last row from right to left
    for (int k = 0; k < n - 1; k++)
    {
        cout << arr[i][j] << " ";
        j--;
    }

    // Print elements in the first column from bottom to top
    for (int k = 0; k < n - 1; k++)
    {
        cout << arr[i][j] << " ";
        i--;
    }

    return 0;
}
