/*
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.



Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

*/
#include <vector>
#include <string>
#include <stack>

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st; // Stack to store scores
        int n = operations.size();

        // Iterate through each operation
        for (int i = 0; i < n; i++)
        {
            if (operations[i] == "C")
            { // Cancel the last valid round's score
                st.pop();
            }
            else if (operations[i] == "D")
            { // Double the last valid round's score
                int num = 2 * st.top();
                st.push(num);
            }
            else if (operations[i] == "+")
            { // Add the last two valid round's scores
                int curr = st.top();
                st.pop();
                int prev = st.top();
                int newNum = curr + prev;
                st.push(curr);
                st.push(newNum);
            }
            else
            { // Number: push the score onto the stack
                st.push(stoi(operations[i]));
            }
        }

        // Calculate the total score
        int sum = 0;
        while (!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
