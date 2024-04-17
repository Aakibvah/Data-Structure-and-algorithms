/*
Given a positive integer N, print count of set bits in it.

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110'
So the count of the set bit is 2.
time: O(LogN)
space: O(1)
*/

class Solution
{
public:
    int setBits(int N)
    {
        // Initialize a counter to keep track of the number of set bits
        int countSetBits = 0;

        // Iterate through each bit position from 0 to 31 (assuming a 32-bit integer)
        for (int i = 0; i < 32; i++)
        {
            // Check if the ith bit of N is set using bitwise AND operation with (1 << i)
            if (N & (1 << i))
            {
                // If the ith bit is set, increment the set bit counter
                countSetBits++;
            }
        }

        // Return the total count of set bits in N
        return countSetBits;
    }
};
