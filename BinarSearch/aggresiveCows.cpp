/*
You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.

Example 1:

Input:
n=5
k=3
stalls = [1 2 4 8 9]
Output:
3
Explanation:
The first cow can be placed at stalls[0],
the second cow can be placed at stalls[2] and
the third cow can be placed at stalls[3].
The minimum distance between cows, in this case, is 3,
which also is the largest among all possible ways.
*/

class Solution
{
public:
    int solve(int n, int k, vector<int> &stalls)
    {
        // Sort the stalls in ascending order
        sort(stalls.begin(), stalls.end());

        // Initialize variables
        int cows = 1;                         // Number of cows placed
        int low = 1;                          // Minimum possible distance between cows
        int high = stalls[n - 1] - stalls[0]; // Maximum possible distance between cows
        int last = stalls[0];                 // Position of the last placed cow

        // Binary search for the maximum minimum distance between cows
        while (low <= high)
        {
            int mid = low + (high - low) / 2; // Midpoint of distance range

            // Check if the current distance is feasible
            for (int i = 1; i < n; i++)
            {
                if ((stalls[i] - last) >= mid)
                {                     // If the distance is greater than or equal to mid
                    cows++;           // Place another cow
                    last = stalls[i]; // Update the position of the last placed cow
                }
            }

            // Adjust distance range based on feasibility
            if (cows >= k)
            {                  // If enough cows are placed
                low = mid + 1; // Increase the minimum distance
            }
            else
            {                   // If not enough cows are placed
                high = mid - 1; // Decrease the maximum distance
            }

            // Reset variables for the next iteration
            last = stalls[0]; // Reset the position of the last placed cow
            cows = 1;         // Reset the number of cows placed
        }

        return high; // Return the maximum minimum distance between cows
    }
};
