/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.



Example 1:

Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
Example 2:

Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.
Example 3:

Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/
class Solution
{
public
    int pivotIndex(vector<int> &nums)
    {
        int total = 0;   // Variable to store the running sum
        vector<int> sum; // Vector to store the running sums

        if (nums.size() == 1) // If there is only one element, it is the pivot index
            return 0;

        // Calculate the running sum for each element in the vector
        for (int i = 0; i < nums.size(); i++)
        {
            total += nums[i];
            sum.push_back(total); // Append the running sum to the vector
        }

        // Check if any index is a pivot index
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                if ((sum[0] - sum[nums.size() - 1]) == 0)
                    return 0; // If the sum of elements to the right is 0, then the pivot index is 0.
            }
            else if (sum[i - 1] == (sum[nums.size() - 1] - sum[i]))
                return i; // If the sums of elements on both sides are equal, return the index as pivot index
        }

        return -1; // If no pivot index is found, return -1
    }
}