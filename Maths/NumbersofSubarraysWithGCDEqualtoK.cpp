/*
iven an integer array nums and an integer k, return the number of subarrays of nums where the greatest common divisor of the subarray's elements is k.

A subarray is a contiguous non-empty sequence of elements within an array.

The greatest common divisor of an array is the largest integer that evenly divides all the array elements.
Example 1:
Input: nums = [9,3,1,2,6,3], k = 3
Output: 4
Explanation: The subarrays of nums where 3 is the greatest common divisor of all the subarray's elements are:
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
- [9,3,1,2,6,3]
*/
class Solution
{
public:
    int subarrayGCD(vector<int> &nums, int k)
    {
        // Check if nums has only one element and that element is equal to k
        if (nums.size() == 1 && nums[0] == k)
            return 1;

        // Check if nums has only one element, return 0 if it doesn't meet the previous condition
        if (nums.size() == 1)
            return 0;

        int cnt = 0; // Initialize a counter for the number of subarrays with GCD equal to k

        for (int i = 0; i < nums.size(); i++)
        {
            int gcd = nums[i]; // Initialize gcd as the current element

            for (int j = i; j < nums.size(); j++)
            {
                gcd = __gcd(gcd, nums[j]); // Update gcd by taking the GCD with the next element

                if (gcd == k)
                {
                    cnt++; // Increment the counter if gcd is equal to k
                }

                // Break the loop if gcd becomes less than k
                if (gcd < k)
                    break;
            }
        }

        return cnt; // Return the count of subarrays with GCD equal to k
    }
};
