/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].
*/

class Solution
{
public:
    int countOdds(int low, int high)
    {
        int diff, ans;

        diff = high - low + 1; // Calculate the range difference

        // Check if both low and high are odd
        if (low % 2 != 0 && high % 2 != 0)
            ans = (diff / 2) + 1; // If both are odd, add one to half of the range
        else
            ans = diff / 2; // Otherwise, simply take half of the range

        return ans; // Return the count of odd numbers in the range
    }
};
