/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

class Solution
{
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // Calculate sizes of both arrays
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Ensure nums1 is the smaller array
        if (n1 > n2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Calculate total size and the index to find the median
        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;

        // Binary search in nums1
        int low = 0;
        int high = n1;

        while (low <= high)
        {
            // Calculate mid index for nums1
            int m1 = low + (high - low) / 2;
            // Calculate corresponding mid index for nums2
            int m2 = left - m1;

            // Initialize left and right values for both arrays
            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;

            // Assign values if indices are within bounds
            if (m1 < n1)
                r1 = nums1[m1];
            if (m2 < n2)
                r2 = nums2[m2];
            if (m1 - 1 >= 0)
                l1 = nums1[m1 - 1];
            if (m2 - 1 >= 0)
                l2 = nums2[m2 - 1];

            // Check if partition is correct
            if (l1 <= r2 && l2 <= r1)
            {
                // If total size is odd, return the maximum of left partitions
                if (n % 2 == 1)
                    return max(l1, l2);
                // If total size is even, return the average of maximum of left and minimum of right partitions
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
            // If partition is not correct, adjust the search range
            else if (l1 > r2)
                high = m1 - 1;
            else
                low = m1 + 1;
        }

        // Return 0 if no median found
        return 0;
    }
};
