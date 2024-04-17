/*
Given a number N and a bit number K, check if Kth index bit of N is set or not. A bit is called set if it is 1. Position of set bit '1' should be indexed starting with 0 from LSB side in binary representation of the number.
Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

Example 1:

Input:
N = 4
K = 0
Output:
No
Explanation:
Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Example 2:

Input:
N = 4
K = 2
Output:
Yes

time: O(1)
space: O(1)
*/

class Solution
{
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Perform bitwise AND operation between n and (1 << k)
        // If the Kth bit is set, the result will be non-zero, indicating true
        // If the Kth bit is not set, the result will be zero, indicating false
        return n & (1 << k);
    }
};
