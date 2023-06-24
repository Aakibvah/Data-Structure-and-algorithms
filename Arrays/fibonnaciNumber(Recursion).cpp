/*
The Fibonacci numbers, commonly denoted F(n) form a sequence,
 called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
*/

class Solution
{
public:
    int fib(int n)
    {
        if (n == 1)
            return n;
        if (n == 0)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
};