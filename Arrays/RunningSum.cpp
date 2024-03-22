/*
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
Example 2:

Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
*/
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        // Create a vector to store the running sum
        vector<int> ans(nums.size());

        // Initialize the first element of the running sum vector with the first element of nums
        ans[0] = nums[0];

        // Iterate through the nums vector starting from the second element
        for (int i = 1; i < nums.size(); i++)
        {
            // Calculate the running sum by adding the current element of nums to the previous running sum
            ans[i] = ans[i - 1] + nums[i];
        }

        // Return the vector containing the running sum
        return ans;
    }
};
