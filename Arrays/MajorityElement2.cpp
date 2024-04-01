/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Handle edge case when array has only one element
        if (nums.size() == 1)
            return {nums[0]}; // Return the single element as the majority element

        // Initialize variables for tracking counts and values of potential majority elements
        int cnt1 = 1, cnt2 = 0;         // Counters for two potential majority elements
        int val1 = nums[0], val2 = -10; // Values of two potential majority elements
        int n = nums.size();            // Size of the input array

        // Iterate through the array to find potential majority elements
        for (int i = 1; i < nums.size(); i++)
        {
            if (cnt2 == 0 && nums[i] != val1)
            {
                cnt2 = 1;
                val2 = nums[i];
            }
            else if (cnt1 == 0 && nums[i] != val2)
            {
                cnt1 = 1;
                val1 = nums[i];
            }
            else if (nums[i] == val1)
            {
                cnt1++;
            }
            else if (nums[i] == val2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        // Count occurrences of potential majority elements in the array
        int c1 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val1)
                c1++;
            if (nums[i] == val2)
                c2++;
        }

        // Check if potential majority elements occur more than n/3 times and add them to the result
        vector<int> ans;
        if (c1 > n / 3)
        {
            ans.push_back(val1);
        }
        if (c2 > n / 3)
        {
            ans.push_back(val2);
        }

        return ans; // Return the vector containing majority elements
    }
};
