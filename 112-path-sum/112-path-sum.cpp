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
    bool ans = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        helper(root,sum,targetSum);
        return ans;
    }
    
    void helper(TreeNode* root,int &sum,int target){
        if(root==NULL)
            return;
        sum += root->val;
        helper(root->left,sum,target);
        helper(root->right,sum,target);
        if(root->left==NULL && root->right==NULL && sum==target)
            ans = true;
        sum -= root->val;
        return;
    }
};