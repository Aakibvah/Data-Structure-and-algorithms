/*
735. Asteroid Collision
Solved
Medium
Topics
Companies
Hint
We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        stack<int> st;

        // Traverse through the array of asteroids
        for (int i = 0; i < a.size(); i++)
        {
            // If stack is empty or the current asteroid is moving to the right, push it to the stack
            if (st.empty() || a[i] > 0)
            {
                st.push(a[i]);
            }
            else
            {
                // Handle collisions
                while (true)
                {
                    // If the top of the stack is moving to the left and the current asteroid is moving to the right,
                    // push the current asteroid to the stack and exit the loop
                    if (st.top() < 0)
                    {
                        st.push(a[i]);
                        break;
                    }
                    // If the top of the stack has the same absolute size as the current asteroid,
                    // both asteroids will explode and pop the top asteroid from the stack and exit the loop
                    else if (st.top() == -a[i])
                    {
                        st.pop();
                        break;
                    }
                    // If the top of the stack has a larger size than the current asteroid,
                    // the current asteroid will explode, so exit the loop
                    else if (st.top() > -a[i])
                    {
                        break;
                    }
                    else
                    {
                        // If the top of the stack has a smaller size than the current asteroid,
                        // pop the top asteroid from the stack. If the stack becomes empty, push the current asteroid to the stack.
                        st.pop();
                        if (st.empty())
                        {
                            st.push(a[i]);
                            break;
                        }
                    }
                }
            }
        }

        // Transfer the stack elements to the result vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i)
        {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};