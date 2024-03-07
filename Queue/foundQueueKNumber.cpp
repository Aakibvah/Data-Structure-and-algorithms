/*
Given K, Print the Kth Number in the increasing series of number using digits 1 and 2 only.
Input Format

The only line contains number K
Constraints

1<= K <=20
Output Format

Return the kth number of the series
Sample Input 0

5
Sample Output 0

21
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int k;
    cin >> k;
    queue<string> q;
    q.push("1");
    q.push("2");
    string ans;
    for (int i = 1; i <= k; i++)
    {
        string temp = q.front();
        q.pop();

        if (i == k)
        {
            cout << temp;
        }
        q.push(temp + "1");
        q.push(temp + "2");
    }
    return 0;
}