/*
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.

Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.

Example 1:

Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8}
X = 9
Output:
1 8
4 5
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.
Example 2:
Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0}
X = 8
Output:
4 4
5 3
*/

class Solution
{
public:
    vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        int check = 0;
        // Your code goes here
        unordered_map<int, int> mp;
        vector<pair<int, int>> ans;
        for (int i = 0; i < N; i++)
        {
            mp[X - A[i]] = A[i];
        }
        for (int j = 0; j < M; j++)
        {
            if (mp.find(B[j]) != mp.end())
                ans.push_back(make_pair(mp[B[j]], B[j]));
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};