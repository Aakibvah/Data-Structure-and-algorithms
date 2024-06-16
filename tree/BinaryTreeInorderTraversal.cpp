/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
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
    // Function to perform inorder traversal of a binary tree
    vector<int> inorderTraversal(TreeNode *root)
    {
        // Vector to store the traversal result
        vector<int> result;
        // Call the recursive helper function for inorder traversal
        InTrav(root, result);
        return result; // Return the traversal result
    }

    // Recursive helper function for inorder traversal
    void InTrav(TreeNode *root, vector<int> &a)
    {
        // Base case: If the current node is null, return
        if (root == nullptr)
            return;

        // Recursive call on the left subtree
        InTrav(root->left, a);
        // Process the current node: Add its value to the result vector
        a.push_back(root->val);
        // Recursive call on the right subtree
        InTrav(root->right, a);
    }
};

// MORRIS TRAVERSAL TIME O(n) space O(1)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {}; // If the tree is empty, return an empty vector

        vector<int> inorder; // Vector to store the inorder traversal

        TreeNode *curr = root; // Initialize current node to root

        // Morris Inorder Traversal
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                // If there is no left child, visit the current node and go to the right
                inorder.push_back(curr->val);
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
                    curr = curr->left;
                }
                else
                {
                    // Revert the changes made in the tree
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder; // Return the inorder traversal
    }
};
