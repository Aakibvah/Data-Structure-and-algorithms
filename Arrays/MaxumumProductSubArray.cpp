/*
Given an integer array nums, find a
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // Initialize variables
        int prefix = 1;      // Prefix product initialized to 1
        int suffix = 1;      // Suffix product initialized to 1
        int ans = INT_MIN;   // Initialize answer to minimum integer value
        int n = nums.size(); // Get the size of the input array

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Handle cases where prefix or suffix becomes 0 to avoid multiplication by 0
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            // Update prefix and suffix products
            prefix = prefix * nums[i];         // Multiply prefix by current element
            suffix = suffix * nums[n - i - 1]; // Multiply suffix by element from end of array

            // Update answer with maximum of current answer, prefix, and suffix products
            ans = max(ans, max(prefix, suffix));
        }
        return ans; // Return the maximum product of subarrays
    }
};
