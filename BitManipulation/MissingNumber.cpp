/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3].
2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2].
2 is the missing number in the range since it does not appear in nums.
*/
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int idx = 0; // Initialize the XOR result variable
        int num = 0; // This variable seems unused

        // Calculate the XOR of all numbers from 1 to n (inclusive)
        for (int i = 1; i <= nums.size(); i++)
        {
            idx ^= i;
        }

        // Calculate the XOR of all numbers in the given array
        for (int i = 0; i < nums.size(); i++)
        {
            idx ^= nums[i];
        }

        // Return the result, which will be the missing number
        return idx;
    }
};
