/*
Given an array arr[] of N positive elements. The task is to find the Maximum AND Value generated by any pair(arri, arrj) from the array such that i != j.
Input Format

The first line contains size of array.
Second line contains the elements of the array.
Constraints

1 <= N <= 10^5
1 <= arr[i] <= 10^5
Output Format

Output the required integer.
Sample Input 0
4
4 8 12 16
Sample Output 0
8

time: O(32*2N) - > (64*N) - > (N)
space: (1)
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
    int arr[n];
    // Read elements into the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Iterate through each bit from the most significant bit to the least significant bit
    for (int i = 31; i >= 0; i--)
    {
        int cnt = 0;
        // Count the number of elements with the ith bit set to 1
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
                cnt++;
        }
        // If there are at least two elements with the ith bit set to 1, set all other bits to 0
        if (cnt >= 2)
        {
            for (int k = 0; k < n; k++)
            {
                if ((arr[k] & (1 << i)) == 0)
                    arr[k] = 0;
            }
        }
    }

    int element1 = -1;
    int element2 = -1;

    // Find the first positive element in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && element1 == -1)
        {
            element1 = arr[i];
        }
        else if (arr[i] > 0 && element1 != -1)
        {
            element2 = arr[i];
            break;
        }
    }
    // Print the bitwise AND of the two elements
    cout << (element1 & element2);
    return 0;
}
