class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        vector<int> dp(n + 1); // Resize the vector to hold n+1 elements
        dp[0] = 0;             // Base case for Fibonacci number 0
        dp[1] = 1;             // Base case for Fibonacci number 1

        // Calculate Fibonacci numbers from the bottom-up using dynamic programming
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // Recurrence relation: F(n) = F(n-1) + F(n-2)
        }

        return dp[n]; // Return the nth Fibonacci number
    }
};