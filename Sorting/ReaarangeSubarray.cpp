/*
Given N elements and [s,e], Rearrange the SubArray so that

a) arr[s] should go to correct sorted position in [s,e]
b) all elements <=arr[s] should go to leftside of arr[s]
c) all elements > arr[s] should go to rightside of arr[s]
Input Format

The first line contains three integers n, s and e representing the size of array. subarray start and subarray end.
The second line contains n elements of array.
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the array after rearranging the subarray.
Sample Input 0

11 2 4
10 3 8 15 6 12 2 18 7 15 14
Sample Output 0

10 3 6 8 15 12 2 18 7 15 14
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read the size of the array and the subarray range
    int n, s, e;
    cin >> n >> s >> e;

    // Declare an array of size n
    int arr[n];

    // Input elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int p1 = s + 1;
    int p2 = e;

    // Partition the subarray using the element at index s as the pivot
    while (p1 <= p2)
    {
        if (arr[p1] <= arr[s])
        { // Move p1 pointer if element is less than or equal to pivot
            p1++;
        }
        else if (arr[p2] > arr[s])
        { // Move p2 pointer if element is greater than pivot
            p2--;
        }
        else
        { // Swap elements to partition them around the pivot
            int temp = arr[p1];
            arr[p1] = arr[p2];
            arr[p2] = temp;
            p1++;
            p2--;
        }
    }

    // Swap pivot element with the last element in the left partition
    int temp = arr[s];
    arr[s] = arr[p2];
    arr[p2] = temp;

    // Print the partitioned subarray
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
