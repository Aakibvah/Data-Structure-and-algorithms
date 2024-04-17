/*
Given numbers n and k, unset the kth bit of number n. Rightmost bit is considered 0th bit and so on.
Input Format

the first line contains two integer n and k.
Constraints

1 <= 10^5 <= n
0 <= k <=31
Output Format

Print the decimal number after unsetiing the kth bit
Sample Input 0
15 1
Sample Output 0
13

time: O(1)
space: O(1)
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k; // Read two integers from standard input

    // Check if the kth bit of n is set using bitwise AND operation with (1 << k)
    if (n & (1 << k))
    {
        // If the kth bit is set, toggle it using XOR operation with (1 << k) and print the result
        cout << (n ^ (1 << k)) << endl;
    }
    else
    {
        // If the kth bit is not set, print n as it is
        cout << n << endl;
    }

    return 0;
}
