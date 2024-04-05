/*
Given an array A[] consisting of 0’s and 1’s. A flip operation is one in which you turn 1 into 0 and a 0 into 1. You have to do at most one “Flip” operation of any subarray. Formally, select a range (l, r) in the array A[], such that (0 ≤ l ≤ r < n) holds and flip the elements in this range to get the maximum ones in the final array. You can possibly make zero operations to get the answer. You are asked to return the maximum number of 1 you can get in the array after doing flip operation.

Example 1:

Input:
N = 5
A[] = {1, 0, 0, 1, 0}
Output:
4
Explanation:
We can perform a flip operation in the range [1,2]
After flip operation array is : [ 1 1 1 1 0 ]
Count of one after fliping is : 4
[Note: the subarray marked in bold is the flipped subarray]
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        int cnt = 0; // Count of 0s in the array
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                a[i] = 1; // Convert 0 to 1
            }
            else
            {
                a[i] = -1; // Convert 1 to -1
                cnt++;     // Increment count of 0s
            }
        }

        int curSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (curSum >= 0)
            {
                curSum += a[i]; // Add the current element to the current sum if it doesn't make it negative
            }
            else
            {
                curSum = a[i]; // Start a new sum from the current element if the current sum becomes negative
            }
            maxSum = max(maxSum, curSum); // Update the maximum sum encountered so far
        }

        if (maxSum > 0)
        {
            return maxSum + cnt; // Return the maximum sum plus the count of 0s (flipped 1s)
        }

        return cnt; // If the maximum sum is not positive, return just the count of 0s
    }
};
