/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
time: O(N)
space:O(1)
*/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // Initialize the answer variable to store the single occurring element
        int ans = 0;

        // Iterate through each bit position from 0 to 31
        for (int i = 0; i < 32; i++)
        {
            // Initialize a counter to keep track of the number of set bits at the current bit position
            int countBits = 0;

            // Iterate through all elements in the array
            for (int j = 0; j < nums.size(); j++)
            {
                // Check if the current element's bit at the current bit position is set
                if (nums[j] & (1 << i))
                {
                    countBits++; // Increment the count of set bits
                }
            }

            // If the count of set bits at the current bit position is not a multiple of 3, it contributes to the single occurring element
            if (countBits % 3)
            {
                ans += (1 << i); // Add the bit to the answer
            }
        }

        // Return the final answer containing the single occurring element
        return ans;
    }
};
