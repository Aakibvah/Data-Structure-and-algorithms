/*
You are given an integer array arr.
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
 After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
*/
class Solution
{
public:
    // Function to find the maximum number of chunks to make the array sorted
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();    // Get the size of the input array
        vector<int> pfxMax(n); // Initialize a prefix maximum array of size n
        vector<int> sfxMin(n); // Initialize a suffix minimum array of size n
        int curMax = INT_MIN;  // Initialize the current maximum to the minimum integer value
        int curMin = INT_MAX;  // Initialize the current minimum to the maximum integer value

        // Calculate the prefix maximum array
        for (int i = 0; i < n; i++)
        {
            curMax = max(curMax, arr[i]); // Update the current maximum
            pfxMax[i] = curMax;           // Store the current maximum in the prefix maximum array
        }

        // Calculate the suffix minimum array
        for (int i = n - 1; i >= 0; i--)
        {
            curMin = min(curMin, arr[i]); // Update the current minimum
            sfxMin[i] = curMin;           // Store the current minimum in the suffix minimum array
        }

        int cnt = 0; // Initialize the count of chunks to 0
        // Count the number of chunks where the prefix maximum is less than or equal to the suffix minimum
        for (int i = 0; i < n - 1; i++)
        {
            if (pfxMax[i] <= sfxMin[i + 1])
            {
                cnt++;
            }
        }
        return ++cnt; // Return the maximum number of chunks
    }
};
