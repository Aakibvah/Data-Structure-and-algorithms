/*
Write a function that takes the binary representation of a positive integer and returns the number of
set bits
 it has (also known as the Hamming weight).



Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.

Example 2:

Input: n = 128

Output: 1

Explanation:

The input binary string 10000000 has a total of one set bit.
*/
class Solution
{
public:
    int hammingWeight(int n)
    {
        int cnt = 0; // Initialize count of set bits to 0

        // Iterate through each bit position from 0 to 31
        for (int i = 0; i < 32; i++)
        {
            // Check if the ith bit of n is set to 1
            if (n & (1 << i))
            {
                cnt++; // Increment the count of set bits
            }
        }

        return cnt; // Return the count of set bits
    }
};
