/*
Given a string s which represents an expression, evaluate this expression and return its value.
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/
class Solution
{
public:
    // Function to perform an arithmetic operation based on operator
    int operation(int val1, int val2, char op)
    {
        if (op == '*')
            return val1 * val2;
        else if (op == '/')
            return val1 / val2;
        else if (op == '+')
            return val1 + val2;
        else
            return val1 - val2;
    }

    // Function to determine the precedence of an operator
    int precedence(char op)
    {
        if (op == '*' || op == '/')
            return 1;

        return 0;
    }

    // Function to evaluate the expression
    int calculate(string s)
    {
        stack<int> operand; // Stack to store operands
        stack<char> optor;  // Stack to store operators
        int i = 0;
        while (i < s.length())
        {
            int num = 0;
            if (s[i] >= '0' && s[i] <= '9')
            { // If character is a digit
                while (i < s.length() && s[i] >= '0' && s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                operand.push(num); // Push the operand onto the operand stack
                i--;
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            { // If character is an operator
                while (optor.size() > 0 && precedence(optor.top()) >= precedence(s[i]))
                {
                    // Evaluate operations with higher precedence
                    int val2 = operand.top();
                    operand.pop();
                    int val1 = operand.top();
                    operand.pop();
                    char op = optor.top();
                    optor.pop();
                    int result = operation(val1, val2, op);
                    operand.push(result); // Push the result onto the operand stack
                }
                optor.push(s[i]); // Push the current operator onto the operator stack
            }

            i++;
        }

        // Evaluate remaining operations
        while (optor.size() > 0)
        {
            int val2 = operand.top();
            operand.pop();
            int val1 = operand.top();
            operand.pop();
            char op = optor.top();
            optor.pop();
            int result = operation(val1, val2, op);
            operand.push(result); // Push the result onto the operand stack
        }

        return operand.top(); // Return the final result
    }
};

// better optimize soln
class Solution
{
public:
    int calculate(string s)
    {
        int length = s.length();
        if (length == 0)
            return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++)
        {
            char currentChar = s[i];
            if (isdigit(currentChar))
            {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1)
            {
                if (sign == '+' || sign == '-')
                {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                }
                else if (sign == '*')
                {
                    lastNumber = lastNumber * currentNumber;
                }
                else if (sign == '/')
                {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
};