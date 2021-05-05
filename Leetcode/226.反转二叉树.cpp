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
    void Dfs(TreeNode* root)
    {
        if (root == nullptr) return;

        auto tmp = root->left;
        root->left = root->right;
        root->right = tmp;

         Dfs(root->left);
         Dfs(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        Dfs(root);
        return root;
    }
};
