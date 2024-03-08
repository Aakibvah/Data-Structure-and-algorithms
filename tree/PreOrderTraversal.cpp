/*
144. Binary Tree Preorder Traversal
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the preorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
*/
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to perform preorder traversal of a binary tree
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        // Call the recursive helper function for preorder traversal
        preTrav(root, result);
        return result;
    }

    // Recursive helper function for preorder traversal
    void preTrav(TreeNode *root, vector<int> &a)
    {
        // Base case: If the current node is null, return
        if (root == nullptr)
            return;

        // Process the current node: Add its value to the result vector
        a.push_back(root->val);

        // Recursive call on the left subtree
        preTrav(root->left, a);
        // Recursive call on the right subtree
        preTrav(root->right, a);
    }
};
