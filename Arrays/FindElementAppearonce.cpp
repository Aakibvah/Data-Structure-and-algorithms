/*
Given a sorted array A[] of N positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

Example 1:

Input:
N = 5
A = {1, 1, 2, 5, 5}
Output: 2
Explanation:
Since 2 occurs once, while
other numbers occur twice,
2 is the answer.
Example 2:

Input:
N = 7
A = {2, 2, 5, 5, 20, 30, 30}
Output: 20
Explanation:
Since 20 occurs once, while
other numbers occur twice,
20 is the answer.
*/
class Solution
{
public:
    int search(int A[], int N)
    {
        // code
        for (int i = 0; i < N; i += 2) // increasing i by 2 bcz each number apperarence twice except one
        {
            if (A[i] != A[i + 1])
                return A[i];
        }
    }
};