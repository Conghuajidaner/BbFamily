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
    map<int, vector<int>>buf;

    void Dfs(TreeNode* root, int deep)
    {
        if (root == nullptr) return;
        buf[deep].push_back(root->val);

        Dfs(root-> left, deep + 1);
        Dfs(root-> right, deep + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        Dfs(root, 0);
        for (auto v: buf)
            ans.push_back(v.second.back());
        return ans;
    }
};
