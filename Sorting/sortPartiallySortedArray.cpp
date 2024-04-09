/*
Given N elements, first N-1 elements are sorted, Sort entire array and Print it.
Input Format

The first line contains integer n representing the size of array
The second line contains n elements of array.
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the sorted array in a line separated by space
Sample Input 0

6
2 6 10 14 20 4
Sample Output 0

2 4 6 10 14 20
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read the size of the array
    int n;
    cin >> n;

    // Declare an array of size n
    int a[n];

    // Input elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Bubble sort algorithm to sort the array
    for (int j = n - 2; j >= 0; j--)
    {
        if (a[j] > a[j + 1])
        { // If current element is greater than its adjacent element, swap them
            swap(a[j], a[j + 1]);
        }
        else
        {
            break; // If no more swaps needed, break the loop
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
