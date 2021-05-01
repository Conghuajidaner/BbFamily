/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>buf;
    void Dfs(TreeNode* root)
    {
        if (root == nullptr) return;
        Dfs(root->left);
        buf.push_back(root->val);
        Dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        Dfs(root);
        for (int i = 1; i < buf.size(); ++ i)
            if (buf[i] <= buf[i - 1])
                return false;
        return true;
    }
};
