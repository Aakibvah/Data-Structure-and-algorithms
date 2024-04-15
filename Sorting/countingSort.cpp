/*
Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

Example 1:

Input:
N = 5
S = "edsab"
Output:
abdes
Explanation:
In lexicographical order, string will be
abdes.
Example 2:

Input:
N = 13
S = "geeksforgeeks"
Output:
eeeefggkkorss
Explanation:
In lexicographical order, string will be
eeeefggkkorss.
time: O(N)
space: O(N+string.length)
*/
class Solution
{
public:
    // Function to arrange all letters of a string in lexicographical
    // order using Counting Sort.
    string countSort(string str)
    {
        int arr[26] = {0}; // Array to store count of each letter, initialized to zeros

        // Count the occurrences of each letter in the input string
        for (int i = 0; i < str.length(); i++)
        {
            int asc = (int)str[i]; // Get ASCII value of current character
            arr[asc - 97]++;       // Increment count for the corresponding letter in the array
        }

        string st = ""; // Initialize an empty string to store the sorted string

        // Construct the sorted string based on the counts in the array
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] > 0)
            {
                // Append the current letter (converted from ASCII) to the sorted string
                for (int j = 0; j < arr[i]; j++)
                {
                    st += (char)(i + 97); // Convert ASCII value back to character
                }
            }
        }

        return st; // Return the sorted string
    }
};
