/*
rite a program to find the transpose of a square matrix of size N*N.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
Input Format

First line contains an integer N
Next N lines contain the matrix with N numbers in each line.
Constraints

1<=N<=10^3
-10^9<=mat[i][j]<=10^9
Output Format

Output N lines containing the transposed matrix with N numbers in each line.
Sample Input 0

4
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4
Sample Output 0

1 2 3 4
1 2 3 4
1 2 3 4
1 2 3 4
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

    int mat[n][n]; // Declare a square matrix of size n x n

    // Read the elements of the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    // Transpose the matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(mat[i][j], mat[j][i]); // Swap elements to transpose the matrix
        }
    }

    // Print the transposed matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " "; // Print each element of the transposed matrix
        }
        cout << endl; // Move to the next line after printing each row
    }
    return 0; // Return 0 to indicate successful execution
}
