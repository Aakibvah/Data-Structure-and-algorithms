/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
*/

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        int lp = 0;
        int rp = 1;
        sort(nums.begin(), nums.end());
        while (rp != nums.size())
        {
            if (nums[lp] == nums[rp])
                return true;
            else
            {
                lp++;
                rp++;
            }
        }
        return false;
    }
};