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
    vector<vector<int>>ans;
    int targetSum;
    void Dfs(TreeNode* root, vector<int>path, int cur)
    {
        if (root -> left == nullptr && root -> right == nullptr)
        {
            path.push_back(root->val);
            if (cur + root -> val == targetSum)
                ans.push_back(path);
            return;
        }
        path.push_back(root -> val);
        if (root->left)     Dfs(root->left, path,cur + root->val);
        if (root->right)    Dfs(root->right, path, cur + root-> val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if (root == nullptr) return ans;
        targetSum = t;
        vector<int>tmp;
        Dfs(root, tmp, 0);
        return ans;
    }
};
