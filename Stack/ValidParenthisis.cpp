/*
20. Valid Parentheses
Solved
Easy
Topics
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Create a stack to store opening brackets

        if (s.size() == 1) // If the string has only one character, it cannot be valid
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (st.size() == 0 || s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                // If the stack is empty or the current character is an opening bracket,
                // push it onto the stack
                st.push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    if (st.top() == '(')
                        st.pop(); // If the current character is a closing bracket and it matches the top of the stack, pop the top element
                    else
                        return false; // If it doesn't match or the stack is empty, the string is invalid
                }
                else if (s[i] == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
                else
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            }
        }

        if (st.size() == 0)
        {
            return true; // If the stack is empty after iterating through the string, the string is valid
        }
        else
        {
            return false; // If the stack is not empty, the string is invalid
        }
    }
};