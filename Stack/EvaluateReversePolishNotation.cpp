/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

class Solution
{
public:
    // Function to perform arithmetic calculation based on the operator
    int calculation(int val1, int val2, string op)
    {
        if (op == "*")
            return val1 * val2;
        else if (op == "/")
            return val1 / val2;
        else if (op == "+")
            return val1 + val2;
        else
            return val1 - val2;
    }

    // Function to evaluate the Reverse Polish Notation (RPN) expression
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> operand;
        string ch;
        int i = 0;
        // Loop through each token in the RPN expression
        while (i < n)
        {
            ch = tokens[i];
            // If the token is an operator, perform calculation
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
            {
                int val2 = operand.top();
                operand.pop();
                int val1 = operand.top();
                operand.pop();
                // Perform calculation using the calculation function
                int res = calculation(val1, val2, ch);
                operand.push(res);
            }
            else
            {
                // If the token is an operand, convert it to integer and push onto the stack
                operand.push(stoi(ch));
            }
            i++;
        }
        // The final result is at the top of the stack
        return operand.top();
    }
};
