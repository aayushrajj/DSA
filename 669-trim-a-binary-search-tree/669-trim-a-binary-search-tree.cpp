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
        if(root->val > high)
            return helper(root->left,low,high);
        if(root->val < low)
            return helper(root->right,low,high);
        
        root->left = helper(root->left,low,high);
        root->right = helper(root->right,low,high);
        return root;
    }
};