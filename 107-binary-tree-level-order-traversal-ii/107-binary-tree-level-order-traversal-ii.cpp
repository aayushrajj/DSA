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
        int d = depth(root);
        vector<vector<int>> res(d,vector<int> {});
        helper(res,root,d-1);
        return res;
    }
    
    int depth(TreeNode* root){
        if(root==NULL)
            return 0;
        return max(depth(root->left) , depth(root->right))+1;
    }
    
    void helper(vector<vector<int>> &res,TreeNode* root,int depth){
        if(root==NULL)
            return;
        res[depth].push_back(root->val);
        helper(res,root->left,depth-1);
        helper(res,root->right,depth-1);
    }
};