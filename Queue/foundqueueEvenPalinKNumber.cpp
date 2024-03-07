/*
Given K, Print the Kth Palindrome Number in the increasing series of even digit numbers using digits 1 and 2 only.
Input Format

The only line contains number K
Constraints

1<= K <=20
Output Format

Return the kth number of the series
Sample Input 0

5
Sample Output 0

2112
*/
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    // Read input value k from standard input
    int k;
    cin >> k;

    // Create a queue to store strings
    queue<string> q;

    // Initialize the queue with the first two strings in the sequence
    q.push("11");
    q.push("22");

    // Iterate from 1 to k
    for (int i = 1; i <= k; i++)
    {
        // Retrieve the front string from the queue
        string temp = q.front();
        q.pop();

        // If the current iteration matches k, print the string
        if (i == k)
        {
            cout << temp;
        }

        // Split the string into two halves
        string left = temp.substr(0, temp.size() / 2);
        string right = temp.substr(temp.size() / 2, temp.size());

        // Insert "11" or "22" into the middle of the string, creating two new strings
        q.push(left + "11" + right);
        q.push(left + "22" + right);
    }

    return 0;
}
