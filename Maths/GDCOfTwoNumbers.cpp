/*
Given two positive integers a and b, find GCD of a and b.

Note: Don't use the inbuilt gcd function

Example 1:

Input:
a = 3
b = 6
Output: 3
Explanation: GCD of 3 and 6 is 3

Example 2:

Input:
a = 1
b = 1
Output: 1
Explanation: GCD of 1 and 1 is 1

time: O(logN)
SPACE: O(logN) stack space
*/
class Solution
{
public:
    // Recursive function to calculate the greatest common divisor (GCD) of two integers a and b
    int gcd(int a, int b)
    {
        // If a is zero, return b as the GCD
        if (a == 0)
            return b;

        // Otherwise, recursively call gcd with b % a as the first argument and a as the second argument
        int ans = gcd(b % a, a);

        return ans; // Return the computed GCD
    }
};
