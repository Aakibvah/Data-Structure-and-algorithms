/*
Given an array a of integers of length n, find the nearest smaller number for every element such that the smaller element is on left side.If no small element present on the left print -1.

Example 1:

Input: n = 3
a = {1, 6, 2}
Output: -1 1 1
Explaination: There is no number at the
left of 1. Smaller number than 6 and 2 is 1.
Example 2:

Input: n = 6
a = {1, 5, 0, 3, 4, 5}
Output: -1 1 -1 0 3 4
Explaination: Upto 3 it is easy to see
the smaller numbers. But for 4 the smaller
numbers are 1, 0 and 3. But among them 3
is closest. Similary for 5 it is 4.
*/

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[])
    {
        // code here
        // Initialize a vector to store the results, initially filled with -1
        vector<int> ans(n);

        // Initialize a stack to keep track of indices
        stack<int> st;

        // Loop through each element in the array
        for (int i = n - 1; i >= 0; i--)
        {
            // While the stack is not empty and the current element is smaller than the element at the top of the stack
            while (st.size() > 0 && a[i] < a[st.top()])
            {
                // Get the index of the element at the top of the stack
                int idx = st.top();
                // Pop the element from the stack
                st.pop();
                // Update the result vector at the index with the current element
                ans[idx] = a[i];
            }

            // Push the current index onto the stack
            st.push(i);
        }

        // If there are elements remaining in the stack
        while (st.size() > 0)
        {
            // Get the index of the element at the top of the stack
            int idx = st.top();
            // Pop the element from the stack
            st.pop();
            // Set the corresponding element in the result vector to -1
            ans[idx] = -1;
        }

        // Return the result vector
        return ans;
    }
};