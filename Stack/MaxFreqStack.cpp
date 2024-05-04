/*
Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.


Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
*/

class FreqStack
{
public:
    // Map to store the frequency of each element
    unordered_map<int, int> freqMap;

    // Map to store stacks of elements grouped by their frequency
    unordered_map<int, stack<int>> setMap;

    // Variable to track the maximum frequency
    int maxFreq;

    // Constructor initializes maxFreq to 0
    FreqStack()
    {
        maxFreq = 0;
    }

    // Method to push an element onto the frequency stack
    void push(int val)
    {
        // Increment the frequency of the element
        int freq = freqMap[val] + 1;
        freqMap[val] = freq;

        // Update maxFreq if necessary
        if (freq > maxFreq)
            maxFreq = freq;

        // Push the element onto the stack corresponding to its frequency
        setMap[freq].push(val);
    }

    // Method to pop the element with the highest frequency from the frequency stack
    int pop()
    {
        // Get the top element from the stack with the maximum frequency
        int top = setMap[maxFreq].top();
        setMap[maxFreq].pop();

        // Decrement the frequency of the popped element
        freqMap[top]--;

        // Update maxFreq if the stack with the maximum frequency becomes empty
        if (setMap[maxFreq].size() == 0)
            maxFreq--;

        // Return the popped element
        return top;
    }
};
