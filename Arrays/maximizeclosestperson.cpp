/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat,
 and seats[i] = 0 represents that the ith seat is empty (0-indexed).
There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return that maximum distance to the closest person.
Example 1:
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
*/
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        // Initialize variables to track consecutive zeros and maximum zeros
        int preZeros = -1;    // Number of consecutive zeros before the current sequence
        int suffixZeros = -1; // Number of consecutive zeros after the current sequence
        int maxZeros = -1;    // Maximum consecutive zeros encountered
        int zeros = 0;        // Count of consecutive zeros in the current sequence

        // Iterate through the seats array
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 0)
            {
                zeros++; // Increment zeros count for consecutive zeros
            }
            else
            {
                // Update preZeros, maxZeros, and reset zeros when encountering a person
                if (preZeros == -1)
                {
                    preZeros = zeros; // Update preZeros if first sequence of zeros
                }
                else
                {
                    maxZeros = max(maxZeros, zeros); // Update maxZeros with maximum consecutive zeros
                }
                zeros = 0; // Reset zeros count for next sequence
            }
        }
        suffixZeros = zeros; // Update suffixZeros with consecutive zeros at the end of the row

        // Calculate the maximum distance to the closest person using the formula
        return max(max(suffixZeros, preZeros), (maxZeros + 1) / 2);
        // The formula considers distance from start, distance from end, and maximum distance in between
    }
};
