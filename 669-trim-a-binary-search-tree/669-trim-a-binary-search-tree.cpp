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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return helper(root,low,high);
    }
    
    TreeNode* helper(TreeNode* root, int low , int high){
        if(root==NULL)
            return root;
        if(root->val >= low && root->val <= high){
            root->left = helper(root->left,low,high);
            root->right = helper(root->right,low,high);
        } 
        else if(root->val > high)
            root = helper(root->left,low,high);
        else if(root->val < low)
            root = helper(root->right,low,high);
        return root;
    }
};