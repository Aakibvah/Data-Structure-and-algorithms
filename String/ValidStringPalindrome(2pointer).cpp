/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int lp = 0;
        int rp = s.size() - 1;
        while (lp < rp)
        {

            if (isalnum(s[lp]) && isalnum(s[rp]))
            {
                if (tolower(s[lp]) == tolower(s[rp]))
                {
                    lp++;
                    rp--;
                }
                else
                    return false;
            }
            else if (!isalnum(s[lp]))
                lp++;
            else
                rp--;
        }
        return true;
    }
};