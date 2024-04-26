/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i].
Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example 1:
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
*/
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        // Initialize the search range
        int low = *max_element(weights.begin(), weights.end());   // Lowest possible capacity (at least the maximum weight)
        int high = accumulate(weights.begin(), weights.end(), 0); // Highest possible capacity (sum of all weights)
        int ans = high;                                           // Initialize the answer to a value greater than the maximum possible capacity

        // Binary search for the minimum valid capacity
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Midpoint of the current range
            int totalDays = 1;                // Initialize total days needed
            int sum = 0;                      // Initialize sum of weights for a day

            // Calculate total days needed for the current capacity (mid)
            for (int weight : weights)
            {
                if (sum + weight > mid)
                {
                    totalDays++; // Increase days needed if current sum exceeds capacity
                    sum = 0;     // Reset sum for the next day
                }
                sum += weight; // Add weight to the current day's sum
            }

            // Adjust the search range based on total days needed
            if (totalDays > days)
            {
                low = mid + 1; // Increase low to search in the higher capacity range
            }
            else
            {
                ans = mid;      // Update the answer to the current valid capacity
                high = mid - 1; // Decrease high to search in the lower capacity range
            }
        }

        return ans; // Return the minimum valid capacity found
    }
};
