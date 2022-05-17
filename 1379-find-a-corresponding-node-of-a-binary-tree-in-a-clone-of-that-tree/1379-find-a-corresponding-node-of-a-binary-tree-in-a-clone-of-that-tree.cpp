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
    TreeNode* res = NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        preOrder(original,cloned,target);
        return res;
    }
    
    void preOrder(TreeNode* root,TreeNode* cloned, TreeNode* &check){
        if(root==NULL)
            return;
        if(root==check)
            res = cloned;
        preOrder(root->left,cloned->left,check);
        preOrder(root->right,cloned->right,check);
    }
};