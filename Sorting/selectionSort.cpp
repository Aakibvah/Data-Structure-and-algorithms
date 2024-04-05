/*
Given N array Integers, Sort the array using Selection sort technique
Input Format

Integer representing N representing length of array
N numbers of Array
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the sorted array in a line separated by space
Sample Input 0

5
7 9 3 10 4
Sample Output 0

3 4 7 9 10
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // Read the size of the array

    int a[n];
    // Input elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ele = INT_MIN; // Initialize ele to a very small value
    int idx = -1;      // Initialize idx to an invalid index
    // Perform selection sort
    for (int i = 0; i < n - 1; i++)
    {
        ele = a[i]; // Assume the current element is the smallest
        idx = i;    // Assume the current index is the index of the smallest element
        // Find the minimum element and its index in the remaining unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < ele)
            {
                ele = a[j];
                idx = j;
            }
        }
        // Swap the current element with the minimum element found
        swap(a[i], a[idx]);
    }

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
