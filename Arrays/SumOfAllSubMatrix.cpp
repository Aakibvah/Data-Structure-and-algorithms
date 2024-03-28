/*
Given a NxM 2-D matrix, the task to find the sum of all the submatrices.
Input Format

The first line contains two integers n and m.
Each of next n line contains m integers.
Constraints

1 <= n,m <= 100
1 <= mat[i][j] <= 100
Output Format

Return the sum of all the submatrices.
Sample Input 0

2 2
1 2
3 4
Sample Output 0

40
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read input for the size of the matrix (n rows, m columns)
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int arr[n][m]; // Declare a matrix of size n x m

    // Input elements into the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Calculate the sum based on occurrences in submatrices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Calculate the number of occurrences of arr[i][j] in submatrices
            int occ = (i + 1) * (j + 1) * (n - i) * (m - j);
            ans += (occ * arr[i][j]); // Update the sum
        }
    }

    // Output the final sum
    cout << ans;

    return 0;
}
