/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]
time: O(n)
space: O(1)
*/
class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xxory = 0;

        // Step 1: Find the XOR of all elements in the array
        for (int i = 0; i < nums.size(); i++)
        {
            xxory ^= nums[i];
        }

        // Step 2: Find the rightmost set bit in xxory
        long long rightMostBit = (xxory & -(xxory));

        // Initialize variables to store the two unique numbers
        int x = 0, y = 0;

        // Step 3: Separate the numbers based on the rightmost set bit
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] & rightMostBit) != 0)
            {
                x ^= nums[i]; // XOR with numbers having the rightmost bit set
            }
            else
            {
                y ^= nums[i]; // XOR with numbers having the rightmost bit not set
            }
        }

        // Return a vector containing the two unique numbers
        return {x, y};
    }
};
