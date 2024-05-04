/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days.
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day,
 for which the price of the stock on the given day is less than or equal to its price on the current day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input:
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span
100 is greater than equal to 100 and there are no more elements behind it so the span is 1,
80 is greater than equal to 80 and smaller than 100 so the span is 1,
60 is greater than equal to 60 and smaller than 80 so the span is 1,
70 is greater than equal to 60,70 and smaller than 80 so the span is 2,
60 is greater than equal to 60 and smaller than 70 so the span is 1,
75 is greater than equal to 60,70,60,75 and smaller than 100 so the span is 4,
85 is greater than equal to 80,60,70,60,75,85 and smaller than 100 so the span is 6.
Hence the output will be 1 1 1 2 1 4 6.
*/
#include <vector>
#include <stack>

class Solution
{
public:
    // Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Initialize a vector to store the span for each day
        vector<int> ans(n);

        // Initialize a stack to keep track of indices of previous stock prices
        stack<int> st;

        // Iterate through each day's stock price
        for (int i = 0; i < n; i++)
        {
            // While the stack is not empty and the current stock price is greater than or equal to the price at the top of the stack
            while (!st.empty() && price[i] >= price[st.top()])
            {
                // Pop elements from the stack as long as the current price is greater than or equal to the price at the top of the stack
                st.pop();
            }

            // Calculate the span for the current day: current day - index of the nearest previous day whose price is greater than the current day's price
            ans[i] = (st.empty()) ? (i + 1) : (i - st.top());

            // Push the current day's index onto the stack
            st.push(i);
        }

        // Return the vector containing the spans for each day
        return ans;
    }
};
