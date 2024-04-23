/*
Given an array arr[] of length N ≥ 2. The task is to remove an element from the given array such that the GCD of the array after removing it is maximized.
Input Format

The first line contains the length of array N
The second line contains N element representing the element of Array
Constraints

1 <= N <= 10^4
1 <= arr[i] <= 10^9
Output Format

The maximum Possible GCD after deleting 1 element
Sample Input 0

5
24 16 18 30 15
Sample Output 0

3
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the GCD of two integers
int pgcd(int a, int b)
{
    return __gcd(a, b); // Using the built-in __gcd function from <algorithm> header
}

// Function to calculate the GCD of two integers
int sgcd(int a, int b)
{
    return __gcd(a, b); // Using the built-in __gcd function from <algorithm> header
}

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

    int prefixGcd[n];      // Array to store prefix GCDs
    prefixGcd[0] = arr[0]; // Initialize the first element as the prefix GCD

    // Calculate prefix GCDs
    for (int i = 1; i < n; i++)
    {
        prefixGcd[i] = pgcd(prefixGcd[i - 1], arr[i]);
    }

    int suffixGcd[n];              // Array to store suffix GCDs
    suffixGcd[n - 1] = arr[n - 1]; // Initialize the last element as the suffix GCD

    // Calculate suffix GCDs
    for (int i = n - 2; i >= 0; i--)
    {
        suffixGcd[i] = sgcd(arr[i], suffixGcd[i + 1]);
    }

    int ans = 0; // Initialize the maximum GCD as 0

    // Update ans using suffix GCDs
    ans = max(ans, suffixGcd[1]);

    // Iterate through each element of the array to calculate overall GCDs
    for (int i = 1; i < n; i++)
    {
        int left = prefixGcd[i - 1];         // Left part of the array for overall GCD calculation
        int right = suffixGcd[i + 1];        // Right part of the array for overall GCD calculation
        int overallGcd = __gcd(left, right); // Calculate overall GCD

        ans = max(ans, overallGcd); // Update ans with the maximum GCD
    }

    // Update ans using prefix GCDs
    ans = max(ans, prefixGcd[n - 2]);

    cout << ans; // Print the maximum GCD

    return 0;
}
