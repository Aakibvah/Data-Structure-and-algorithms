#include <iostream>
usiong namespace std;

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
*/

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lp = 0;
        int rp = nums.size() - 1;

        while (lp <= rp)
        {
            if (nums[lp] > nums[rp])
                lp++;
            else
                rp--;
        }
        return nums[lp];
    }
};