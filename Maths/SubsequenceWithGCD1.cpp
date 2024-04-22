/*
Given N integers, Check if there exists a subsequence with gcd == 1.
Input Format

The first line contains the length of array N
The second line contains N element representing the element of Array
Constraints

1 <= N <= 10^4
1 <= arr[i] <= 10^9
Output Format

Output true if there exists a subsequence with GCD 1 else Output false.
Sample Input 0

4
4 6 3 8
Sample Output 0

true
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n; // Read the size of the array

    int arr[n]; // Declare an array to store the integers

    // Read each integer into the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int overallGcd = 0; // Initialize the overall GCD as 0
    // Calculate the overall GCD of the array using the built-in __gcd function
    for (int i = 0; i < n; i++)
    {
        overallGcd = __gcd(overallGcd, arr[i]);
    }

    // Check if the overall GCD is equal to 1 and print the result
    if (overallGcd == 1)
        cout << "true";
    else
        cout << "false";

    return 0;
}
