/*
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them,
 the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.
Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation:
We can split into two chunks, such as [1, 0], [2, 3, 4].
However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.
*/

class Solution
{
public:
    // Function to find the maximum number of chunks to make the array sorted
    int maxChunksToSorted(vector<int> &arr)
    {
        int count = 0;            // Initialize the count of chunks to 0
        int maxTillNow = INT_MIN; // Initialize the maximum element seen so far to the minimum integer value

        // Iterate through the array
        for (int i = 0; i < arr.size(); i++)
        {
            maxTillNow = max(maxTillNow, arr[i]); // Update the maximum element seen so far

            // If the current index is equal to the maximum element seen so far
            if (i == maxTillNow)
            {
                count++; // Increment the count of chunks
            }
        }
        return count; // Return the maximum number of chunks
    }
};
