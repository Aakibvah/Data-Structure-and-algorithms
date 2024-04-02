/*
Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.



Example 1:

Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.

*/

class Solution
{
public:
    vector<int> replaceElements(vector<int> &a)
    {
        // Check if the input vector has only one element
        if (a.size() == 1)
            return {-1}; // Return {-1} as specified in the problem

        int newMax = -1; // Initialize newMax to -1

        // Traverse the input vector from right to left
        for (int i = a.size() - 1; i >= 0; i--)
        {
            // If the current element is greater than newMax
            if (a[i] > newMax)
            {
                int temp = a[i];            // Store the current element in temp
                a[i] = newMax;              // Replace the current element with newMax
                newMax = max(newMax, temp); // Update newMax to the maximum of itself and the current element
            }
            else
            {
                a[i] = newMax; // Replace the current element with newMax
            }
        }

        return a; // Return the modified input vector
    }
};
