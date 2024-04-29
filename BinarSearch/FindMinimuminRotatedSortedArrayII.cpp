/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.



Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
*/

class Solution
{
public:
    // Function to find the minimum element in a rotated sorted array
    int findMin(vector<int> &nums)
    {
        // Initialize pointers for binary search
        int low = 0;
        int high = nums.size() - 1;
        // Initialize variable to store the index of the minimum element
        int ans = -1;

        // Perform binary search
        while (low <= high)
        {
            // Calculate middle index
            int mid = low + (high - low) / 2;

            // Handle duplicate values at start, middle, and end
            if (nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                // Move pointers to avoid duplicate values
                low++;
                high--;
                // Update ans if current mid is smaller than previous ans
                if (ans == -1 || nums[mid] < nums[ans])
                    ans = mid;
            }
            // If right half is sorted
            else if (nums[mid] <= nums[high])
            {
                // Update ans if current mid is smaller than previous ans
                if (ans == -1 || nums[mid] < nums[ans])
                    ans = mid;
                // Update high pointer
                high = mid - 1;
            }
            // If left half is sorted
            else
            {
                // Update ans if current low is smaller than previous ans
                if (ans == -1 || nums[low] < nums[ans])
                    ans = low;
                // Update low pointer
                low = mid + 1;
            }
        }

        // Return the minimum element found
        return nums[ans];
    }
};
