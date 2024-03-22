/*
Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:
Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]
*/

class NumArray
{
public:
    vector<int> pf; // Prefix sum array
    NumArray(vector<int> &nums)
    {
        pf.resize(nums.size() + 1); // Resize prefix sum array

        // Calculate prefix sums
        pf[0] = nums[0]; // Initialize first element of prefix sum array
        for (int i = 1; i < nums.size(); i++)
        {
            pf[i] = pf[i - 1] + nums[i]; // Calculate prefix sum for each element
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return pf[right]; // Return prefix sum at right if left is 0
        else
            return pf[right] - pf[left - 1]; // Calculate sum using prefix sums
    }
};
