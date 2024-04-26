/*
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
*/

class Solution
{
public:
    long long minTime(int arr[], int n, int k)
    {
        // Initialize variables
        long long time = 0;        // Time taken to paint each board
        long long painters = 1;    // Number of painters needed
        int low = INT_MIN;         // Lowest possible time
        long long overallTime = 0; // Overall minimum time

        // Find the maximum element in the array (maximum time per board)
        for (int i = 0; i < n; i++)
        {
            low = max(arr[i], low);
        }

        // Calculate the total time if all boards are painted by one painter
        long long high = accumulate(arr, arr + n, 0LL); // 0LL ensures long long arithmetic

        // Binary search for the minimum time
        while (low <= high)
        {
            long long mid = low + (high - low) / 2; // Midpoint of time range

            // Check if the current time is feasible
            for (int i = 0; i < n; i++)
            {
                if (time + arr[i] > mid)
                {               // If adding current board exceeds the time limit
                    time = 0;   // Reset time for the next painter
                    painters++; // Increment painters required
                }

                time += arr[i]; // Add current board's time to total time
            }

            // Adjust time range based on feasibility
            if (painters > k)
            { // Too many painters needed, increase time
                low = mid + 1;
            }
            else
            { // Feasible time, reduce time
                high = mid - 1;
                overallTime = mid; // Update overall minimum time
            }

            // Reset variables for the next iteration
            painters = 1;
            time = 0;
        }

        return overallTime; // Return the minimum overall time
    }
};
