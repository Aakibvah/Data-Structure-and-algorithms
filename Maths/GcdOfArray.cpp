/*
Given N integers, Calculate the GCD of all the numbers
Input Format

The first line contains the length of array N
The second line contains N element representing the element of Array
Constraints

1 <= N <= 10^4
1 <= arr[i] <= 10^9
Output Format

Output the final GCD of Number
Sample Input 0

3
6 12 15
Sample Output 0
3

time: O(NlogN)
space: O(logn)
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the greatest common divisor (GCD) of two integers using Euclid's algorithm
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    int ans = gcd(b % a, a);

    return ans;
}

int main()
{
    int n;
    cin >> n; // Read the size of the array

    int arr[n]; // Declare an array to store the integers

    int arrayGcd = 0; // Initialize the GCD of the array as 0
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read each integer into the array
    }

    // Calculate the GCD of the array using the gcd function
    for (int i = 0; i < n; i++)
    {
        arrayGcd = gcd(arrayGcd, arr[i]);
    }

    cout << arrayGcd; // Print the calculated GCD of the array
    return 0;
}
