/*
Given an array, find maximum sum of smallest and second smallest elements chosen from all possible sub-arrays. More formally, if we write all (nC2) sub-arrays of array of size >=2 and find the sum of smallest and second smallest, then our answer will be maximum sum among them.


Example 1:

Input : arr[] = [4, 3, 1, 5, 6]
Output : 11
Subarrays with smallest and
second smallest are,
[4, 3]
smallest = 3    second smallest = 4
[4, 3, 1]
smallest = 1    second smallest = 3
[4, 3, 1, 5]
smallest = 1    second smallest = 3
[4, 3, 1, 5, 6]
smallest = 1    second smallest = 3
[3, 1]
smallest = 1    second smallest = 3
[3, 1, 5]
smallest = 1    second smallest = 3
[3, 1, 5, 6]
smallest = 1    second smallest = 3
[1, 5]
smallest = 1    second smallest = 5
[1, 5, 6]
smallest = 1    second smallest = 5
[5, 6]
smallest = 5    second smallest = 6
Maximum sum among all
above choices is, 5 + 6 = 11

Example 2:
Input : arr[] = {5, 4, 3, 1, 6}
Output : 9

*/

class Solution
{
public:
    long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long maxSum = 0;
        long long sum = 0;

        long long L = 0;
        long long R = 1;

        while (R < N)
        {
            sum = arr[L] + arr[R];

            maxSum = max(sum, maxSum);

            sum = 0;
            L++;
            R++;
        }
        return maxSum;
    }
};
