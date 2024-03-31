/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int i = 0; // Initialize index for iteration

        // Iterate through the array
        while (i < nums.size())
        {
            // Check if current element is less than 1, greater than array size, or already in correct position
            if (nums[i] < 1 || nums[i] > nums.size() || i == nums[i] - 1)
            {
                i++; // Move to the next element
            }
            else
            {
                // Swap elements to place each positive integer x at index x - 1 if possible
                int idx = nums[i] - 1;
                if (nums[i] == nums[idx])
                {
                    i++; // If duplicate, move to the next element
                }
                else
                {
                    swap(nums[idx], nums[i]); // Swap elements to place nums[i] at correct position
                }
            }
        }

        // Iterate through the modified array to find the first missing positive integer
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
            {
                // Return the first missing positive integer
                return i + 1;
            }
        }

        // If all positive integers from 1 to nums.size() are present, return nums.size() + 1
        return (long)nums.size() + 1;
    }
};
