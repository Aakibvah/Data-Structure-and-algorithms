/*
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.
Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
*/
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
    {
        int si = 0;        // Initialize start index
        int ei = 0;        // Initialize end index
        int count = 0;     // Initialize count of valid subarrays
        int prevCount = 0; // Initialize count of valid subarrays ending at previous index

        while (ei < nums.size())
        { // Loop until end index is within bounds
            if (nums[ei] >= left && nums[ei] <= right)
            {                            // If element at end index is within range
                prevCount = ei - si + 1; // Update count of valid subarrays ending at current index
                count += prevCount;      // Add count of valid subarrays ending at current index to total count
            }
            else if (nums[ei] < left)
            {                       // If element at end index is less than left bound
                count += prevCount; // Add count of valid subarrays ending at previous index to total count
            }
            else
            {                  // If element at end index is greater than right bound
                si = ei + 1;   // Update start index to next index
                prevCount = 0; // Reset count of valid subarrays ending at previous index
            }

            ei++; // Move end index forward
        }
        return count; // Return total count of valid subarrays
    }
};
