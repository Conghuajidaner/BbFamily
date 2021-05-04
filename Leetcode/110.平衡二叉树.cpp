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
    bool ans = true;

    int Dfs(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int left = Dfs(root -> left);
        int right = Dfs(root -> right);
        
        if (abs(left - right) > 1) ans = false;

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        Dfs(root);
        return ans;
    }
};
