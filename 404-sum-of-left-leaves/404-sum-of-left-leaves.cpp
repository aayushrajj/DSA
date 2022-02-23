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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root,0);
        return sum;
    }
    
    void helper(TreeNode* root,int flag){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && flag==1){
            sum += root->val;
            return;
        }
        helper(root->left,1);
        helper(root->right,0);
    }
};