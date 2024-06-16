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

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {}; // If the tree is empty, return an empty vector

        vector<int> preorder; // Vector to store the inorder traversal

        TreeNode *curr = root; // Initialize current node to root

        // Morris Inorder Traversal
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                // If there is no left child, visit the current node and go to the right
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                // Find the inorder predecessor of the current node
                TreeNode *prev = curr->left;
                while (prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == NULL)
                {
                    // Make the current node as the right child of its inorder predecessor
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else
                {
                    // Revert the changes made in the tree
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};