/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {

        int low = 0;                // Initialize the low pointer to the start of the array
        int high = nums.size() - 1; // Initialize the high pointer to the end of the array
        int mid;                    // Variable to store the middle index

        if (nums.size() == 1) // If the array contains only one element
            return nums[0];   // Return that element as the result

        while (low <= high)
        {                                 // Perform a binary search until low and high pointers cross each other
            mid = low + (high - low) / 2; // Calculate the middle index

            if (mid < 1 || (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]))
                return nums[mid]; // If the middle element is unique, return it as the result

            if (nums[mid] == nums[mid - 1])
            { // If the middle element is equal to the previous element
                if ((mid + 1) % 2 == 0)
                    low = mid + 1; // If the number of elements up to mid is even, update low to search in the right half
                else
                    high = mid - 1; // If the number of elements up to mid is odd, update high to search in the left half
            }
            else
            { // If the middle element is equal to the next element
                if (mid % 2 == 0)
                    low = mid + 1; // If the number of elements up to mid is even, update low to search in the right half
                else
                    high = mid - 1; // If the number of elements up to mid is odd, update high to search in the left half
            }
        }

        return 0;
    }
};