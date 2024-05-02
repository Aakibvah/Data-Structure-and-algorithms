/*
Given an array arr[ ] of size N having elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input:
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ?
since it doesn't exist, it is -1.
Example 2:

Input:
N = 5, arr[] [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to
6 is 8, for 8 there is no larger elements
hence it is -1, for 0 it is 1 , for 1 it
is 3 and then for 3 there is no larger
element on right and hence -1.
*/
#include <vector>
#include <stack>

class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Your code here

        // Initialize a vector to store the results, initially filled with -1
        vector<long long> ans(arr.size());

        // Initialize a stack to keep track of indices
        stack<long long> st;

        // Loop through each element in the array
        for (int i = 0; i < n; i++)
        {
            // While the stack is not empty and the current element is greater than the element at the top of the stack
            while (st.size() > 0 && arr[i] > arr[st.top()])
            {
                // Get the index of the element at the top of the stack
                int idx = st.top();
                // Pop the element from the stack
                st.pop();
                // Update the result vector at the index with the current element
                ans[idx] = arr[i];
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
