/*
Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes

Example 1:

Input: N = 7, K = 2
arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: 3 4 5 6 7 1 2
Explanation: Rotation of the above
array by 2 will make the output array .

Example 2:

Input: N = 6, K = 12
arr[] = {1, 2, 3, 4, 5, 6}
Output: 1 2 3 4 5 6

*/
class Solution
{

public:
    void leftRotate(int a[], int k, int n)
    {
        // Your code goes here
        reverse(a, a + k);
        reverse(a + k, a + n);
        reverse(a, a + n);
    }
};