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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
    
    bool solve(TreeNode* root,int sum){
        if(root==NULL)
            return false;
        sum -= root->val;
        if(root->left==NULL && root->right==NULL && sum==0)
            return true;
        
        bool left = solve(root->left,sum);
        bool right = solve(root->right,sum);
        
        return left || right;
    }
};