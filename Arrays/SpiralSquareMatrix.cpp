/*
Given a square matrix of N*N, print the Spiral order of the matrix.
Input Format

First line contains an integer n representing size of matrix.
Each of next n lines contain n integer representing array elements.
Constraints

1 <= N <= 100
1 <= arr[i] <= 10^4
Output Format

Print the spiral form of the matrix.
Sample Input 0

3
1 2 3
4 5 6
7 8 9
Sample Output 0

1 2 3 6 9 8 7 4 5
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

    int steps = n - 1; // Initialize the number of steps to n-1
    int i = 0;
    int j = 0;

    // Iterate while there are steps left to process
    while (steps >= 1)
    {
        // Print elements in the current row from left to right
        for (int k = 0; k < steps; k++)
        {
            cout << arr[i][j] << " ";
            j++;
        }

        // Print elements in the current column from top to bottom
        for (int k = 0; k < steps; k++)
        {
            cout << arr[i][j] << " ";
            i++;
        }

        // Print elements in the current row from right to left
        for (int k = 0; k < steps; k++)
        {
            cout << arr[i][j] << " ";
            j--;
        }

        // Print elements in the current column from bottom to top
        for (int k = 0; k < steps; k++)
        {
            cout << arr[i][j] << " ";
            i--;
        }

        // Move to the next starting position
        j++;
        i++;
        steps -= 2; // Reduce the number of steps by 2 for the next iteration

        // If there is only one element left to print, print it and exit the loop
        if (steps == 0)
        {
            cout << arr[i][j] << " ";
            break;
        }
    }

    return 0;
}
