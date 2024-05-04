/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.
Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
*/
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        stack<int> st;          // Stack to store indices of temperatures
        int n = t.size();       // Number of temperatures
        vector<int> days(n, 0); // Vector to store the result

        // Iterate through each day's temperature
        for (int i = 0; i < n; i++)
        {
            // While stack is not empty and current temperature is greater than temperature at the index at the top of the stack
            while (st.size() > 0 && t[i] > t[st.top()])
            {
                // Update the result for the index at the top of the stack
                days[st.top()] = i - st.top();
                // Remove the index from the stack
                st.pop();
            }
            // Push the current index onto the stack
            st.push(i);
        }

        return days; // Return the result
    }
};
