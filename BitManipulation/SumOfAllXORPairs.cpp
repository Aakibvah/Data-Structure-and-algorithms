/*
Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

Example 1:

Input : arr[ ] = {7, 3, 5}
Output : 12
Explanation:
All possible pairs and there Xor
Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
 + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
Example 2:

Input : arr[ ] = {5, 9, 7, 6}
Output :  47
Explanation:
All possible pairs and there Xor
Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
 + (5 ^ 6 = 3) + (9 ^ 7 = 14)
 + (9 ^ 6 = 15) + (7 ^ 6 = 1)
 = 12 + 2 + 3 + 14 + 15 + 1 = 47
*/
class Solution
{
public:
    // Returns sum of bitwise OR of all pairs
    long long int sumXOR(int arr[], int n)
    {
        // Initialize sum to store the final result
        long sum = 0;

        // Iterate through each bit position from 0 to 31
        for (int i = 0; i < 32; i++)
        {
            long zeroCount = 0; // Initialize zeroCount to count the number of elements with the ith bit as 0
            long oneCount = 0;  // Initialize oneCount to count the number of elements with the ith bit as 1

            // Count the number of elements with the ith bit as 0 or 1
            for (int j = 0; j < n; j++)
            {
                if (arr[j] & (1 << i))
                {               // Check if the ith bit of arr[j] is 1
                    oneCount++; // Increment oneCount if the ith bit is 1
                }
                else
                {
                    zeroCount++; // Increment zeroCount if the ith bit is 0
                }
            }

            // Calculate the contribution of the current bit position to the sum
            sum += ((oneCount * zeroCount) * (1 << i));
        }

        return sum; // Return the calculated sum
    }
};
