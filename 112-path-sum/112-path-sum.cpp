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
    bool res = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum,0);
        return res;
    }
    
    void solve(TreeNode* root,int &target,int sum){
        if(root==NULL)
            return;
        sum += root->val;
        solve(root->left,target,sum);
        solve(root->right,target,sum);
        if(root->left==NULL && root->right==NULL && sum==target)
            res = true;
        sum -= root->val;
        return;
    }
};