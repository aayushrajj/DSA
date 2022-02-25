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
        return helper(root,targetSum);
    }
    
    bool helper(TreeNode* root,int target){
        if(root==NULL)
            return false;
        target -= root->val;
        if(root->left==NULL && root->right==NULL && target==0)
            return true;
        int left = helper(root->left,target);
        int right = helper(root->right,target);
        return left || right;
    }
};