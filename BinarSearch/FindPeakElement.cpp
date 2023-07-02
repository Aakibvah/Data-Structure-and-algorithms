/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.



Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int l = 0;               // Initialize the low pointer to the start of the vector
        int h = nums.size() - 1; // Initialize the high pointer to the end of the vector
        int mid;                 // Declare a variable to store the midpoint

        if (nums.size() - 1 == 0) // If the vector contains only one element
            return 0;             // Return the index of that element since it is the peak

        while (l < h)
        {                      // Keep iterating until the low pointer is less than the high pointer
            mid = (l + h) / 2; // Calculate the midpoint

            if (nums[mid] < nums[mid + 1]) // If the element at the midpoint is less than the next element
                l = mid + 1;               // Update the low pointer to search in the right half
            else
                h = mid; // Otherwise, update the high pointer to search in the left half
        }

        return l; // Return the index of the peak element
    }
};