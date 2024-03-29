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

// new code

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1) // If there's only one element in nums
            return nums[0];   // Return that element as the maximum subarray sum

        int sum = 0;       // Initialize sum to keep track of current subarray sum
        int ans = INT_MIN; // Initialize ans to store maximum subarray sum found so far

        for (int i = 0; i < nums.size(); i++)
        { // Iterate through elements of nums
            if (sum >= 0)
            {                   // If current sum is non-negative (previous subarray contributes positively)
                sum += nums[i]; // Add current element to sum (expand current subarray)
            }
            else
            {                  // If current sum is negative (previous subarray contributes negatively)
                sum = nums[i]; // Start a new subarray from current element
            }
            ans = max(sum, ans); // Update ans with maximum of current sum and ans
        }

        return ans; // Return maximum subarray sum
    }
};
