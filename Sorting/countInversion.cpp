/*
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.


Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array
are same, so there is no inversion count.
*/
class Solution
{
public:
    // Function to merge two sorted subarrays and count inversions
    long long int merge(long long int arr[], long long int l, long long int m, long long int r)
    {
        vector<long long int> temp;  // Temporary vector to store merged elements
        long long int left = l;      // Left pointer for the first subarray
        long long int right = m + 1; // Right pointer for the second subarray
        long long int cnt = 0;       // Variable to count inversions

        // Merge the two subarrays into temp vector
        while (left <= m && right <= r)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (m - left + 1); // Count inversions when elements from the second subarray are smaller
                right++;
            }
        }

        // Copy remaining elements from the first subarray to temp vector
        while (left <= m)
        {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from the second subarray to temp vector
        while (right <= r)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy merged elements from temp vector back to arr
        for (long long int i = l; i <= r; i++)
        {
            arr[i] = temp[i - l]; // Adjust index for temp vector
        }

        return cnt; // Return the count of inversions
    }

    // Function to perform merge sort and count inversions
    long long int mergeSort(long long int arr[], long long int l, long long int r)
    {
        long long int cnt = 0; // Initialize inversion count

        if (l < r)
        {
            long long int mid = (l + r) / 2; // Calculate the mid index

            // Recursive calls to mergeSort for left and right halves
            cnt += mergeSort(arr, l, mid);
            cnt += mergeSort(arr, mid + 1, r);

            // Merge the two sorted halves and count inversions
            cnt += merge(arr, l, mid, r);
        }

        return cnt; // Return the total count of inversions
    }

    // Function to calculate the inversion count in the array arr
    long long int inversionCount(long long arr[], long long N)
    {
        // Call mergeSort to perform merge sort and count inversions
        return mergeSort(arr, 0, N - 1);
    }
};
