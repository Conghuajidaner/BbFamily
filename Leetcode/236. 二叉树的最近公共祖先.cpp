/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>pPath, qPath;
    bool Dfs(TreeNode*root, vector<TreeNode*>&path, int target)
    {
        if (root == nullptr) return false;
        if (root -> val == target)
        {
            path.push_back(root);
            return true;
        }
        bool left = Dfs(root -> left, path, target);
        bool right = Dfs(root -> right, path, target);

        if (left || right) { path.push_back(root); return true;}
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pNum, qNum;
        qNum = q->val;
        pNum = p->val;
        
        Dfs(root, pPath, pNum);
        Dfs(root, qPath, qNum);

        // cout << qPath.size() << " " << pPath.size() << endl;
        qPath = vector<TreeNode*>(qPath.rbegin(), qPath.rend());
        pPath = vector<TreeNode*>(pPath.rbegin(), pPath.rend());
        
        for (int i = min(pPath.size(), qPath.size()) - 1; i >= 0; -- i)
            if (pPath[i]->val == qPath[i]->val)
                return pPath[i];
        
        return nullptr;
    }
};
