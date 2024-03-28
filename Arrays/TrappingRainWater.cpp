/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it can trap after raining.
Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 1)
            return 0; // If there's only one bar, no water can be trapped

        // Initialize vectors to store left and right maximum heights
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        // Calculate left maximum heights
        leftMax[0] = height[0];
        for (int i = 1; i < height.size(); i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Calculate right maximum heights
        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int j = height.size() - 2; j >= 0; j--)
        {
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }

        int amount = 0; // Initialize the amount of trapped water
        int contri = 0; // Initialize the contribution of each bar to trapping water

        // Calculate the amount of trapped water between bars
        for (int i = 1; i < height.size() - 1; i++)
        {
            contri = min(leftMax[i - 1], rightMax[i + 1]) - height[i];

            if (contri > 0)
                amount += contri; // Add the contribution to the total amount of trapped water
        }
        return amount; // Return the total amount of trapped water
    }
};
