class Solution {
public:
    double ans;

    double Dfs(TreeNode* root)
    {
        if (root == nullptr) return INT_MIN;

        double left = Dfs(root->left);
        double right = Dfs(root->right);
        ans = max(ans, left);
        ans = max(right, ans);
        ans = max(ans, right + left + (double)root->val);
        return  max((double)root->val + right, max((double)root->val, root->val + left));
    }

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        ans = max(Dfs(root), ans);
        return int(ans);
    }
};
