/*
You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.
Example:
Input:
ABC/-AK/L-*
Output:
*-A/BC-/AKL
Explanation:
The above output is its valid prefix form.
*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    string postToPre(string post_exp)
    {
        stack<string> st; // Stack to store operands and intermediate expressions
        int i = 0;

        // Iterate through the characters of the postfix expression
        while (i < post_exp.length())
        {
            char s = post_exp[i]; // Current character

            // If the current character is an operator
            if (s == '+' || s == '-' || s == '*' || s == '/')
            {
                // Pop the top two elements from the stack
                string val2 = st.top();
                st.pop();
                string val1 = st.top();
                st.pop();

                // Concatenate the operator with the top two operands
                // to form a new expression, then push it back to the stack
                st.push(string(1, s) + val1 + val2);
            }
            else
            {
                // If the current character is an operand, push it onto the stack
                st.push(string(1, s));
            }
            i++;
        }

        // The final result is at the top of the stack
        return st.top();
    }
};
