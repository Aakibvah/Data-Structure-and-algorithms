/*
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10

*/
class Solution
{
public:
    // Function to merge two sorted subarrays within the array arr
    void merge(int arr[], int l, int m, int r)
    {
        vector<int> temp;  // Temporary vector to store merged elements
        int left = l;      // Left pointer for the first subarray
        int right = m + 1; // Right pointer for the second subarray

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
        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[i - l]; // Adjust index for temp vector
        }
    }

    // Function to perform merge sort on the array arr within the indices l and r
    void mergeSort(int arr[], int l, int r)
    {
        if (l == r) // Base case: If the subarray has only one element, return
            return;

        int mid = (l + r) / 2; // Calculate the mid index

        // Recursive calls to mergeSort for left and right halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r);
    }
};
