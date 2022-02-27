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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        helper(res,root,0);
        reverse(res.begin(),res.end());
        return res;
    }
    
    void helper(vector<vector<int>> &res,TreeNode* root,int depth){
        if(root==NULL)
            return;
        if(depth>=res.size())
            res.push_back({});
        res[depth].push_back(root->val);
        helper(res,root->left,depth+1);
        helper(res,root->right,depth+1);
    }
};