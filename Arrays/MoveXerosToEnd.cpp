/*
Given an array arr[] of N positive integers. Push all the zeros of the given array to the right end of the array while maitaining the order of non-zero elements.


Example 1:

Input:
N = 5
Arr[] = {3, 5, 0, 0, 4}
Output: 3 5 4 0 0
Explanation: The non-zero elements
preserve their order while the 0
elements are moved to the right.
Example 2:

Input:
N = 4
Arr[] = {0, 0, 0, 4}
Output: 4 0 0 0
Explanation: 4 is the only non-zero
element and it gets moved to the left.
*/
class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        // code here
        int j;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }
        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[j], arr[i]);
                j++;
            }
        }
    }
};