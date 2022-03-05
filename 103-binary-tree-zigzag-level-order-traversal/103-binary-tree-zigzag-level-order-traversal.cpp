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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root,res,0);
        return res;
    }
    
    void helper(TreeNode* root,vector<vector<int>> &res,int depth){
        if(root==NULL) return;
        if(depth==res.size())
            res.push_back({});
        if(depth%2==0)
            res[depth].push_back(root->val);
        else
            res[depth].insert(res[depth].begin(),root->val);
        helper(root->left,res,depth+1);
        helper(root->right,res,depth+1);
    }
};