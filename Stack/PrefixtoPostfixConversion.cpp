/*
You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.
Example:

Input:
*-A/BC-/AKL
Output:
ABC/-AK/L-*
Explanation:
The above output is its valid postfix form.
*/
class Solution
{
public:
    string preToPost(string pre_exp)
    {
        stack<string> st;             // Stack to store operands and intermediate expressions
        int i = pre_exp.length() - 1; // Start from the end of the prefix expression

        // Iterate through the characters of the prefix expression
        while (i >= 0)
        {
            char ch = pre_exp[i]; // Current character

            // If the current character is an operator
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                // Pop the top two elements from the stack
                string val1 = st.top();
                st.pop();
                string val2 = st.top();
                st.pop();

                // Concatenate the top two operands with the operator
                // to form a new expression, then push it back to the stack
                st.push(val1 + val2 + string(1, ch));
            }
            else
            {
                // If the current character is an operand, push it onto the stack
                st.push(string(1, ch));
            }
            i--;
        }

        // The final result is at the top of the stack
        return st.top();
    }
};
