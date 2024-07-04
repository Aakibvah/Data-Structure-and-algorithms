/*
There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of the same height
(i.e., one unit) but they can be of different widths. The total width of each row is the same.
Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick,
then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
Given the 2D array wall that contains the information about the wall,
return the minimum number of crossed bricks after drawing such a vertical line.

Example 1:
Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
Output: 2
Example 2:

Input: wall = [[1],[1],[1]]
Output: 3
*/
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        // Variable to store the maximum number of aligned gaps
        int ans = 0;
        // Map to store the count of gaps at each position
        map<int, int> bricksGap;

        // Iterate over each row in the wall
        for (vector<int> list : wall)
        {
            int len = 0; // Variable to store the cumulative length of bricks

            // Iterate over each brick in the row except the last one
            for (int i = 0; i < list.size() - 1; i++)
            {
                len += list[i];   // Add the length of the current brick to the cumulative length
                bricksGap[len]++; // Increment the count of the gap position

                // Update the maximum number of aligned gaps found so far
                ans = max(ans, bricksGap[len]);
            }
        }

        // The minimum number of bricks that need to be crossed is the total number of rows minus the maximum number of aligned gaps
        return wall.size() - ans;
    }
};
