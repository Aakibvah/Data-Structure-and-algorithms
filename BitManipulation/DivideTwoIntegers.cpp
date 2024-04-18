/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1,
 then return 231 - 1, and if the quotient is strictly less than -231, then return -231.
Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // Check if dividend and divisor are equal
        if (dividend == divisor)
            return 1;

        long quotient = 0; // Initialize quotient as a long integer to handle overflow
        bool sign = true;  // Initialize the sign of the quotient as positive

        // Determine the sign of the quotient based on the signs of dividend and divisor
        if (dividend >= 0 && divisor < 0)
            sign = false;
        else if (dividend < 0 && divisor >= 0)
            sign = false;

        long n = abs(dividend); // Absolute value of dividend
        long d = abs(divisor);  // Absolute value of divisor

        long long temp = 0; // Temporary variable to store intermediate results

        // Iterate through each bit position from MSB to LSB
        for (int i = 31; i >= 0; i--)
        {
            // Check if adding the current multiple of divisor is within range
            if ((temp + (d << i)) <= n)
            {
                temp += (d << i);           // Add the multiple to the temporary variable
                quotient += ((long)1 << i); // Update the quotient using bit manipulation
            }
        }

        // Check for overflow and adjust the result accordingly
        if (quotient > INT_MAX && sign)
            return INT_MAX;
        else if (quotient < INT_MIN && !sign)
            return INT_MIN;
        else if (!sign)
            return (int)-quotient;

        return (int)quotient; // Return the calculated quotient
    }
};
