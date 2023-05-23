#include <iostream>
#include <vector>
using namespace std;
/*
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
        int p1 = 0;
        int p2 = p1 + 1;
        int ans;
        while (p2 != p1)
        {

            ans = target - nums[p1];
            if (ans == nums[p2])
                return {p1, p2};
            else
                p2++;
            if (p2 > nums.size() - 1)
            {
                p1++;
                p2 = p1 + 1;
            }
        }
        return {-1, -1};
    }
};