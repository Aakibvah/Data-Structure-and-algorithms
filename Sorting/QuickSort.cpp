/*
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.

Example 1:

Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10

Time comp O(NlogN)
space comp (logN)
*/
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high)
        {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        // Your code here
        int p1 = low + 1;
        int p2 = high;

        while (p1 <= p2)
        {
            if (arr[p1] <= arr[low])
            {
                p1++;
            }
            else if (arr[p2] > arr[low])
            {
                p2--;
            }
            else
            {
                std::swap(arr[p1], arr[p2]);
                p1++;
                p2--;
            }
        }
        std::swap(arr[low], arr[p2]);
        return p2;
    }
};
