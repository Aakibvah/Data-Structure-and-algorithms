/*
Given an array arr[] of N positive elements in which every element is repeating four times but 1 element is repeating 1 time. Find the element repeating 1 time.
Input Format

The first line contains size of array.
Second line contains the elements of the array.
Constraints

1 <= N <= 10^5
1 <= arr[i] <= 10^5
Output Format

Output the required number.
Sample Input 0
9
3 2 2 3 1 2 3 3 2
Sample Output 0
1
time: O(N)
space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;   // Read the size of the array from standard input
    int arr[n]; // Declare an array of size n

    int ans = 0; // Initialize the answer variable

    // Read elements into the array from standard input
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Find the single occurring element using XOR operation
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i]; // XOR operation with each element of the array
    }

    // Print the single occurring element
    cout << ans;

    return 0;
}
