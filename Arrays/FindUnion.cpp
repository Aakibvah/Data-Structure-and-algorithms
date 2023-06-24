/*
Union of two arrays can be defined as the common and distinct elements in the two arrays.
Given two sorted arrays of size n and m respectively, find their union.


Example 1:

Input:
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.


Example 2:

Input:
n = 5, arr1[] = {2, 2, 3, 4, 5}
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 1 2 3 4 5
Explanation: Distinct elements including
both the arrays are: 1 2 3 4 5.
*/

class Solution
{
public:
    // arr1,arr2 : the arrays
    //  n, m: size of arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        set<int> ans;
        int i = 0;
        int j = 0;
        ;
        // Your code here
        // return vector with correct order of elements
        while (i < n && j < m)
        {
            if (arr1[i] == arr2[j])
            {
                ans.insert(arr1[i]);
                i++;
                j++;
            }
            else
            {
                ans.insert(arr1[i]);
                ans.insert(arr2[j]);
                i++;
                j++;
            }
        }
        while (i < n)
        {
            ans.insert(arr1[i]);
            i++;
        }
        while (j < m)
        {
            ans.insert(arr2[j]);
            j++;
        }
        vector<int> list;
        for (auto x : ans)
            list.push_back(x);
        return list;
    }
};