/*
Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output:
3 2 1 4 5
Explanation:
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
*/
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    // Function to reverse the order of the first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k)
    {
        // Create a stack to temporarily store the first k elements.
        stack<int> st;

        // Push the first k elements from the queue to the stack.
        for (int i = 0; i < k; i++)
        {
            st.push(q.front()); // Push the front element of the queue to the stack.
            q.pop();            // Remove the front element from the queue.
        }

        // Transfer elements from the stack back to the queue to reverse their order.
        while (!st.empty())
        {
            q.push(st.top()); // Push the top element of the stack to the queue.
            st.pop();         // Pop the top element from the stack.
        }

        // Move the remaining elements after the reversed ones.
        for (int i = 0; i < q.size() - k; i++)
        {
            q.push(q.front()); // Push the front element of the queue to the queue.
            q.pop();           // Remove the front element from the queue.
        }

        return q; // Return the modified queue.
    }
};
