/*
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1

time: O(NlogN)
space: O(1)
*/

bool findPair(int arr[], int size, int n)
{
    // Sort the array in ascending order
    sort(arr, arr + size);

    // Initialize two pointers p1 and p2
    int p1 = 0;
    int p2 = 1;

    // Iterate through the array while both pointers are within bounds
    while (p1 < size && p2 < size)
    {
        // Check if the difference between arr[p2] and arr[p1] is equal to n
        if (p1 != p2 && arr[p2] - arr[p1] == n)
            return true; // Return true if a pair with difference n is found
        else if (arr[p2] - arr[p1] < n)
            p2++; // Move p2 to the right if the difference is less than n
        else
            p1++; // Move p1 to the right if the difference is greater than n
    }

    return false; // Return false if no such pair is found
}
