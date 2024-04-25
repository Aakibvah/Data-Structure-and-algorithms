/*
Given a number N, find the least prime factors for all numbers from 1 to N.  The least prime factor of an integer X is the smallest prime number that divides it.
Note :

1 needs to be printed for 1.
You need to return an array/vector/list of size N+1 and need to use 1-based indexing to store the answer for each number.
Example 1:

Input: N = 6
Output: [0, 1, 2, 3, 2, 5, 2]
Explanation: least prime factor of 1 = 1,
least prime factor of 2 = 2,
least prime factor of 3 = 3,
least prime factor of 4 = 2,
least prime factor of 5 = 5,
least prime factor of 6 = 2.
So answer is[1, 2, 3, 2, 5, 2].
*/

class Solution
{
public:
    vector<int> leastPrimeFactor(int n)
    {
        // Create a vector 'arr' to store the least prime factor for each number
        vector<int> arr(n + 1, 1); // Initialize all elements to 1

        // Apply the least prime factor algorithm
        // Start from 2, the smallest prime number
        for (int i = 2; i <= n; i++)
        {
            // If 'i' is a prime number (its least prime factor is still 1)
            if (arr[i] == 1)
            {
                // Mark 'i' as the least prime factor of 'i'
                arr[i] = i;
                // Mark multiples of 'i' with 'i' as their least prime factor
                // Starting from i * i as smaller multiples have already been marked
                for (int j = i * i; j <= n; j += i)
                {
                    if (arr[j] == 1)
                        arr[j] = i;
                }
            }
        }

        // Create a vector 'leastPrimeFactors' to store the least prime factors
        vector<int> leastPrimeFactors(n + 1, 0);
        for (int i = 1; i <= n; i++)
        { // Start from 1, as arr[0] is not used
            leastPrimeFactors[i] = arr[i];
        }

        return leastPrimeFactors;
    }
};
