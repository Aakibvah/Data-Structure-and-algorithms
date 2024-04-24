/*
You are given an integer array deck where deck[i] represents the number written on the ith card.
Partition the cards into one or more groups such that:
Each group has exactly x cards where x > 1, and
All the cards in one group have the same integer written on them.
Return true if such partition is possible, or false otherwise.
Example 1:
Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
*/
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> freqCount; // Map to store frequency count of elements

        // Count the frequency of each element in the deck
        for (int i = 0; i < deck.size(); i++)
        {
            freqCount[deck[i]]++;
        }

        int gcd = 0; // Initialize the greatest common divisor (GCD) as 0

        // Calculate the GCD of all frequency counts
        for (int i = 0; i < deck.size(); i++)
        {
            gcd = __gcd(gcd, freqCount[deck[i]]);
        }

        // Check if the GCD is greater than 1 (indicating groups of size at least 2)
        if (gcd > 1)
            return true; // Return true if groups of size at least 2 are possible

        return false; // Return false otherwise
    }
};
