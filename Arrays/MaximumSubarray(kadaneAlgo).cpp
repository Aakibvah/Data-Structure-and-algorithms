/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
Runtime: 117 ms, faster than 79.95% of C++ online submissions for Maximum Subarray.
Memory Usage: 67.6 MB, less than 85.62% of C++ online submissions for Maximum Subarray.
*/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int R = 0;
        int maxCount = nums[0];
        int currCount = 0;
        if (nums.size() == 1)
            return nums[0];

        while (R < nums.size())
        {
            currCount = max(currCount, 0);
            currCount += nums[R];
            maxCount = max(maxCount, currCount);
            R++;
        }
        return maxCount;
    }
};