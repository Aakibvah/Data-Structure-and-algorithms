/*
Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.
Example 1:
Input:
N = 10
Output:
2 3 5 7
Explanation:
Prime numbers less than equal to N
are 2 3 5 and 7.
*/
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Create a vector 'arr' to store whether each number is prime or not
        // Initialize all elements to 1, assuming all numbers are prime initially
        vector<int> arr(N + 1, 1);

        // Mark 0 and 1 as non-prime
        arr[0] = arr[1] = 0;

        // Apply Sieve of Eratosthenes algorithm to mark non-prime numbers
        // Start from 2, the smallest prime number
        for (int i = 2; i * i <= N; i++)
        {
            if (arr[i])
            { // If 'i' is prime
                // Mark multiples of 'i' as non-prime starting from i*i
                for (int j = i * i; j <= N; j += i)
                {
                    arr[j] = 0;
                }
            }
        }

        // Create a vector 'prime' to store the prime numbers generated
        vector<int> prime;

        // Add prime numbers to the 'prime' vector
        for (int i = 2; i <= N; i++)
        {
            if (arr[i]) // If 'i' is prime
                prime.push_back(i);
        }

        // Return the vector containing all prime numbers up to 'N'
        return prime;
    }
};
