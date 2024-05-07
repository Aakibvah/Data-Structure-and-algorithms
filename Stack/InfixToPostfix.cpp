/*
Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression
into postfix expression, the resultant
expression will be abcd^e-fgh*+^*+i-
*/

class Solution
{
public:
    // Function to perform calculation between two operands and an operator.
    string calculation(string val1, string val2, char op)
    {
        return val1 + val2 + op; // Concatenate the two operands and the operator
    }

    // Function to determine the precedence of operators.
    int precedence(char c)
    {
        if (c == '^')
            return 3; // Highest precedence for '^' (exponentiation)
        else if (c == '*' || c == '/')
            return 2; // Medium precedence for '*' and '/' (multiplication and division)
        else if (c == '+' || c == '-')
            return 1; // Lowest precedence for '+' and '-' (addition and subtraction)
        return 0;     // Default precedence
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        stack<string> operand; // Stack to store operands
        stack<char> oper;      // Stack to store operators
        int i = 0;

        // Traverse the input infix expression
        while (i < s.length())
        {
            char ch = s[i];
            if (ch == '(')
            {
                oper.push(ch); // Push opening parenthesis onto the operator stack
            }
            else if (ch == ')')
            {
                // Process operators until an opening parenthesis is encountered
                while (!oper.empty() && oper.top() != '(')
                {
                    string val2 = operand.top();
                    operand.pop();
                    string val1 = operand.top();
                    operand.pop();
                    char op = oper.top();
                    oper.pop();
                    string cal = calculation(val1, val2, op); // Perform calculation
                    operand.push(cal);                        // Push result onto operand stack
                }
                oper.pop(); // Pop the opening parenthesis
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            {
                // Process operators based on precedence
                while (!oper.empty() && precedence(oper.top()) >= precedence(ch))
                {
                    char op = oper.top();
                    oper.pop();
                    string val2 = operand.top();
                    operand.pop();
                    string val1 = operand.top();
                    operand.pop();
                    string cal = calculation(val1, val2, op); // Perform calculation
                    operand.push(cal);                        // Push result onto operand stack
                }
                oper.push(ch); // Push current operator onto operator stack
            }
            else
            {
                operand.push(string(1, ch)); // Push operand onto operand stack
            }
            i++;
        }

        // Process remaining operators in the stack
        while (!oper.empty())
        {
            char operatorChar = oper.top();
            oper.pop();
            string val2 = operand.top();
            operand.pop();
            string val1 = operand.top();
            operand.pop();
            string cal = val1 + val2 + operatorChar; // Perform calculation
            operand.push(cal);                       // Push result onto operand stack
        }
        return operand.top(); // Return the final postfix expression
    }
};
