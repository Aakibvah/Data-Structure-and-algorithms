#include <iostream>
#include <vector>
using namespace std;
/*
167. Two Sum II - Input Array Is Sorted
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            if ((nums[left] + nums[right]) == target)
                return {left + 1, right + 1};
            else if ((nums[left] + nums[right]) > target)
            {
                if (nums[left] > nums[right])
                    left++;
                else
                    right--;
            }
            else
            {
                if (nums[left] < nums[right])
                    left++;
                else
                    right--;
            }
        }

        return {0, 0};
    }
};