/*
Given a number N and a value K. From the right, set the Kth bit in the binary representation of N.
The position of Least Significant Bit(or last bit) is 0, the second last bit is 1 and so on.
Example 1:

Input:
N = 10
K = 2
Output:
14
time: O(1)
space: O(1)
*/

class Solution
{
public:
    // Function to set the Kth bit in the integer N.
    int setKthBit(int N, int K)
    {
        // Use bitwise OR operation with (1 << K) to set the Kth bit in N.
        // The expression (1 << K) creates a mask with only the Kth bit set.
        // Bitwise OR with N sets the Kth bit in N without affecting other bits.
        return N | (1 << K);
    }
};
