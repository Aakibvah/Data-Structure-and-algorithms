/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work.
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
Clarification: The input/output format is the same as how LeetCode serializes a binary tree.
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
*/
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        // Check if the tree is empty
        if (!root)
            return "";

        // Queue for level order traversal
        queue<TreeNode *> q;
        // String to store serialized tree
        string str = "";

        // Start with the root node
        q.push(root);

        // Perform level order traversal using BFS
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // Append node value to the string, with ',' as delimiter
            if (!node)
            {
                str.append("#,"); // Use "#" to denote NULL nodes
            }
            else
            {
                str.append(to_string(node->val) + ',');
                q.push(node->left);  // Enqueue left child
                q.push(node->right); // Enqueue right child
            }
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        // Check if the input data is empty
        if (data.empty())
            return nullptr;

        // Use stringstream to parse the input data
        stringstream ss(data);
        string str;

        // Read the root node value from the stringstream
        getline(ss, str, ',');
        int rootVal = stoi(str);
        TreeNode *root = new TreeNode(rootVal);
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            // Deserialize left child
            getline(ss, str, ',');
            if (str == "#")
            {
                node->left = nullptr;
            }
            else
            {
                int leftVal = stoi(str);
                TreeNode *leftNode = new TreeNode(leftVal);
                node->left = leftNode;
                q.push(leftNode);
            }

            // Deserialize right child
            getline(ss, str, ',');
            if (str == "#")
            {
                node->right = nullptr;
            }
            else
            {
                int rightVal = stoi(str);
                TreeNode *rightNode = new TreeNode(rightVal);
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};