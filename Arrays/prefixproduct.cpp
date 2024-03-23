/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // Initialize a vector to store the product except self
        vector<int> prdt(nums.size());
        prdt[0] = nums[0]; // Initialize the first element with nums[0]

        // Calculate prefix products
        for (int i = 1; i < nums.size(); i++)
        {
            prdt[i] = prdt[i - 1] * nums[i]; // Calculate prefix product at each index
        }

        int suffix = 1; // Initialize suffix product as 1

        // Calculate suffix products and combine with prefix products
        for (int i = nums.size() - 1; i > 0; i--)
        {
            prdt[i] = prdt[i - 1] * suffix; // Combine prefix product with suffix product
            suffix *= nums[i];              // Update suffix product for the next iteration
        }
        prdt[0] = suffix; // Set the first element of prdt as the final suffix product

        return prdt; // Return the vector of product except self
    }
};
