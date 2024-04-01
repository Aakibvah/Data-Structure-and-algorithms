/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n.
 If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer,
 return -1.
Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1

*/
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        // Convert the input integer to a string for easier manipulation of digits
        string num = to_string(n);

        // Find the index of the first digit from the right where the digit to its left is smaller
        int idx;
        for (int i = num.size() - 2; i >= 0; i--)
        {
            if (num[i] < num[i + 1])
            {
                idx = i; // Store the index of the digit
                break;
            }
        }

        // If no such digit is found (i.e., digits are in descending order), return -1
        if (idx == -1)
            return -1;

        // Find the smallest digit from the right that is greater than num[idx]
        int smallestIdx = idx + 1;
        for (int i = idx + 1; i < num.size(); i++)
        {
            if (num[i] > num[idx] && num[i] <= num[smallestIdx])
                smallestIdx = i; // Store the index of the smallest digit
        }

        // Swap the digits at idx and smallestIdx to get the next greater integer
        swap(num[idx], num[smallestIdx]);

        // Reverse the digits from idx + 1 to get the smallest possible greater integer
        reverse(num.begin() + idx + 1, num.end());

        // Convert the resulting string back to a long long integer
        long long result = stoll(num);

        // Check if the result is within the 32-bit integer range and greater than the input number n
        if (result > INT32_MAX || result <= n)
        {
            return -1; // Return -1 if result exceeds the range or is not greater than n
        }
        else
        {
            return static_cast<int>(result); // Return the result as an integer
        }
    }
};
