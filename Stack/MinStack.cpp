/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.



Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

#include <stack>
#include <limits>

class MinStack
{
private:
    std::stack<int> main_stack; // Stack to store all elements
    std::stack<int> min_stack;  // Stack to store minimum elements

public:
    /** initialize your data structure here. */
    MinStack() {}

    // Function to push an element onto the stack
    void push(int val)
    {
        // Push the element onto the main stack
        main_stack.push(val);
        // If the min_stack is empty or the current value is less than or equal to the top of min_stack
        if (min_stack.empty() || val <= min_stack.top())
        {
            // Push the current value onto the min_stack
            min_stack.push(val);
        }
    }

    // Function to pop the top element from the stack
    void pop()
    {
        // If the top of main_stack is equal to the top of min_stack
        if (main_stack.top() == min_stack.top())
        {
            // Pop the top element from min_stack
            min_stack.pop();
        }
        // Pop the top element from main_stack
        main_stack.pop();
    }

    // Function to get the top element of the stack
    int top()
    {
        // Return the top element of main_stack
        return main_stack.top();
    }

    // Function to retrieve the minimum element in the stack
    int getMin()
    {
        // Return the top element of min_stack
        return min_stack.top();
    }
};

// soln 2 using single stack

class MinStack
{
public:
    stack<long long> st;      // Stack to store elements and their minimum differences
    long long minimumElement; // Variable to store the minimum element in the stack

    // Constructor initializes minimumElement to 0
    MinStack()
    {
        minimumElement = 0;
    }

    // Method to push an element onto the stack
    void push(int val)
    {
        if (st.empty())
        { // If stack is empty, set minimumElement to val
            minimumElement = val;
            st.push(0ll); // Push difference between val and minimumElement (0 initially)
            return;
        }

        long long difference = val - minimumElement; // Calculate difference between val and minimumElement
        st.push(difference);                         // Push difference onto the stack

        if (val < minimumElement) // Update minimumElement if val is smaller
            minimumElement = val;
    }

    // Method to pop the top element from the stack
    void pop()
    {
        if (st.top() < 0) // If top element represents a smaller element, update minimumElement
            minimumElement = minimumElement - st.top();
        st.pop(); // Pop the top element from the stack
    }

    // Method to return the top element of the stack
    int top()
    {
        if (st.top() < 0) // If top element represents a smaller element, return minimumElement
            return minimumElement;
        return minimumElement + st.top(); // Otherwise, return the actual value
    }

    // Method to return the minimum element in the stack
    int getMin()
    {
        return minimumElement;
    }
};
