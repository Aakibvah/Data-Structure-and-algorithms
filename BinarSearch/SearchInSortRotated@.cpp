/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

class Solution
{
public:
    // Function to search for a target value in a rotated sorted array
    bool search(vector<int> &nums, int target)
    {
        // Initialize pointers for binary search
        int low = 0;
        int high = nums.size() - 1;
        // Initialize variable to store result
        bool ans = false;

        // Perform binary search
        while (low <= high)
        {
            // Calculate middle index
            int mid = low + (high - low) / 2;

            // If target found, return true
            if (nums[mid] == target)
                return true;
            // Handle duplicate values at start, middle, and end
            else if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            // If right half is sorted
            else if (nums[mid] <= nums[high])
            {
                // If target is in right half, update low pointer
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                // If target is not in right half, update high pointer
                else
                    high = mid - 1;
            }
            // If left half is sorted
            else
            {
                // If target is in left half, update high pointer
                if (target >= nums[low] && target <= nums[mid])
                    high = mid - 1;
                // If target is not in left half, update low pointer
                else
                    low = mid + 1;
            }
        }

        // If target not found, return false
        return ans;
    }
};
