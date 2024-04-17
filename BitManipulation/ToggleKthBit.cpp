/*
Given numbers n and k, toggle kth bit of number n. Rightmost bit is considered 0th bit and so on.
Input Format

the first line contains two integer n and k.
Constraints

1 <= 10^5 <= n
0 <= k <=31
Output Format
Print the decimal number after toggling the kth bit

Sample Input 0
75 4
Sample Output 0
91
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

    // Calculate and print the result of n XOR (1 << k)
    // (1 << k) shifts the binary digit 1 by k positions to the left, creating a mask with only the kth bit set
    // n XOR (1 << k) performs a bitwise XOR operation between n and the mask, toggling the kth bit of n
    // The result is printed to standard output with a newline
    cout << (n ^ (1 << k)) << endl;

    return 0;
}
