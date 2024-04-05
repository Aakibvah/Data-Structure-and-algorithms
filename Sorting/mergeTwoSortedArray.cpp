/*
Given two sorted arrays with N and M elements. Merge them into one sorted array and Print them.
Input Format

The first line contains two integers n and m representing the size of 2 arrays
The second line contains n elements of first array.
The third line contains m elements of second array.
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the merged sorted array in a line separated by space
Sample Input 0

4 3
7 10 11 14
3 8 9
Sample Output 0

3 7 8 9 10 11 14
*/
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // Read the sizes of the two arrays

    int arr1[n]; // Declare an array for the first input
    int arr2[m]; // Declare an array for the second input

    // Input elements of the first array
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    // Input elements of the second array
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    int p1 = 0, p2 = 0, p3 = 0;
    int arr3[n + m]; // Declare an array for the merged result

    // Merge the two sorted arrays into the third array
    while (p1 < n && p2 < m)
    {
        if (arr1[p1] <= arr2[p2])
        {
            arr3[p3] = arr1[p1]; // Copy element from arr1 to arr3
            p1++;                // Move to the next element in arr1
        }
        else
        {
            arr3[p3] = arr2[p2]; // Copy element from arr2 to arr3
            p2++;                // Move to the next element in arr2
        }
        p3++; // Move to the next position in arr3
    }

    // Add remaining elements from arr1 to arr3
    while (p1 < n)
    {
        arr3[p3] = arr1[p1]; // Copy remaining elements from arr1 to arr3
        p1++;                // Move to the next element in arr1
        p3++;                // Move to the next position in arr3
    }

    // Add remaining elements from arr2 to arr3
    while (p2 < m)
    {
        arr3[p3] = arr2[p2]; // Copy remaining elements from arr2 to arr3
        p2++;                // Move to the next element in arr2
        p3++;                // Move to the next position in arr3
    }

    // Print the merged array arr3
    for (int i = 0; i < p3; i++)
    {                           // Loop up to the actual size of arr3
        cout << arr3[i] << " "; // Print each element of arr3
    }

    return 0;
}
