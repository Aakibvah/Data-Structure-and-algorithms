/*
Given a sorted arrays with N elements and 3 indices s, m and e such that subarray [s,m] is sorted, subarray [m+1,e] is sorted. Sort the subarray [s,e].

Note: s to m and then m+1 to e are continuous subarray
Input Format

The first line contains integer n representing size of array
The second line contains n elements of array.
The third line contains 3 elements representing s,m and e index.
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the array after sorting subarray [s,e] in a line separated by space
Sample Input 0

12
4 8 -1 2 6 9 11 3 4 7 13 0
2 6 9
Sample Output 0

4 8 -1 2 3 4 6 7 9 11 13 0
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
    cin >> n; // Read the size of the array

    int arr[n]; // Declare an array of size n

    // Input elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int start, mid, end;
    cin >> start >> mid >> end; // Read the indices for the subarrays to merge

    int res[end - start + 1];             // Declare a temporary array to store the merged result
    int p1 = start, p2 = mid + 1, p3 = 0; // Initialize pointers for merging

    // Merge the two subarrays into the temporary array
    while (p1 <= mid && p2 <= end)
    {
        if (arr[p1] < arr[p2])
        {
            res[p3] = arr[p1];
            p1++;
            p3++;
        }
        else
        {
            res[p3] = arr[p2];
            p2++;
            p3++;
        }
    }

    // Copy remaining elements from the first subarray to the temporary array
    while (p1 <= mid)
    {
        res[p3] = arr[p1];
        p1++;
        p3++;
    }

    // Copy remaining elements from the second subarray to the temporary array
    while (p2 <= end)
    {
        res[p3] = arr[p2];
        p2++;
        p3++;
    }

    // Copy the merged result back to the original array within the specified range
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = res[j];
        j++;
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
