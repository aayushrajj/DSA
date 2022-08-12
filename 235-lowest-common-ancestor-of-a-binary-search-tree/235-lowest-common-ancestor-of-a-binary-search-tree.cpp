/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root,p,q);
    }
    
    TreeNode* find(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==NULL)
            return NULL;
        
        if(root==p) return root;
        if(root==q) return root;
        TreeNode* left = find(root->left,p,q);
        TreeNode* right = find(root->right,p,q);
        
        if(left && right)
            return root;
        
        return left==NULL ? right : left;
    }
};