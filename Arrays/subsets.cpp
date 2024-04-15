/*
Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
Time: O
*/

#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums)
    {
        int n = 1 << nums.size();          // Calculate the total number of subsets
        std::vector<std::vector<int>> ans; // Vector to store all subsets

        // Iterate through all possible subsets
        for (int i = 0; i < n; i++)
        {
            std::vector<int> temp; // Temporary vector to store each subset

            // Check each bit of 'i' to determine which elements to include in the current subset
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j))
                { // If the jth bit of 'i' is set (1), include nums[j] in the subset
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp); // Add the current subset to the list of subsets
        }
        return ans; // Return the vector containing all subsets
    }
};
