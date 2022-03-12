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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        int check = root->val;
        return helper(root,check);
    }
    
    bool helper(TreeNode* root,int check){
        if(root==NULL)
            return true;
        if(root->val!=check)
            return false;
        return helper(root->left,check) && helper(root->right,check);
    }
};