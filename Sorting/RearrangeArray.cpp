/*
Given N elements, Rearrange the array so that

a) arr[0] should go to correct sorted position
b) all elements <=arr[0] should go to leftside of arr[0]
c) all elements >arr[0] should go to rightside of arr[0]
Input Format

The first line contains integer n representing the size of array
The second line contains n elements of array.
Constraints

1<= N <= 10 ^ 6
1<= A[i] <=10 ^ 9
Output Format

Print the array after rearranging.
Sample Input 0

11
10 3 8 15 6 12 2 18 7 15 14
Sample Output 0

2 3 8 7 6 10 12 18 15 15 14
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // Read the size of the array
    int n;
    cin >> n;

    // Declare an array of size n
    int arr[n];

    // Input elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int p1 = 1;
    int p2 = n - 1;

    // Partition the array using the first element as the pivot
    while (p1 <= p2)
    {
        if (arr[p1] <= arr[0])
        { // Move p1 pointer if element is less than or equal to pivot
            p1++;
        }
        else if (arr[p2] > arr[0])
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
    int temp = arr[0];
    arr[0] = arr[p2];
    arr[p2] = temp;

    // Print the partitioned array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
