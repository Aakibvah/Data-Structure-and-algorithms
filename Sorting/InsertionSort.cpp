/*
The task is to complete the insert() function which is used to implement Insertion Sort.


Example 1:

Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output:
1 2 3 4 5 6 7 8 9 10
*/
// O(n2)
// space O(1)

class Solution
{
public:
    // Function to insert an element into the sorted part of the array using insertion sort
    void insert(int arr[], int i)
    {
        insertionSort(arr, i); // Call insertion sort function
    }

    // Function to sort the array using insertion sort algorithm
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        { // Start from the second element
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[j] > arr[j + 1])
                { // Swap elements if they are in the wrong order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                else
                {
                    break; // Break the loop if the element is in its correct position
                }
            }
        }
    }
};
