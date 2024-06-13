// idea1
TreeNode *successor(TreeNode root, int val)
{
    vector<Node *> ans;
    inorder(root, ans);
    int idx;
    for (int i = 0 i < ans.size(); i++)
    {
        if (root->val == val)
        {
            idx = i;
            break;
        }
    }

    return ans[idx + 1]->val;
}
void inorder(TreeNode root, vector<Node *> &ans)
{
    if (root == nullptr)
        return nullptr;

    inorder(root->left, ans);
    ans.push_back(root);
    inorder(root->right, ans);
}

// idea2
TreeNode *successor(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;
    int successor;

    while (root != nullptr)
    {
        if (root->val < val)
            root = root->right;
        if (root->val > val)
        {
            successor = root->val;
            root = root->left;
        }
    }
    return successor;
}