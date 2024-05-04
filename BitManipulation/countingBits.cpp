/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.



Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1); // Initialize a vector to store the counts

        // Iterate through each integer from 1 to n
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0; // Initialize count of set bits to 0

            // Iterate through each bit position from 0 to 31
            for (int j = 0; j < 32; j++)
            {
                // Check if the jth bit of i is set to 1
                if (i & (1 << j))
                {
                    cnt++; // Increment the count of set bits
                }
            }

            // Store the count of set bits for i in the vector
            ans[i] = cnt;
        }

        return ans; // Return the vector containing the counts
    }
};
