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
    TreeNode* pruneTree(TreeNode* root) {
        return check(root) ? root : NULL;
    }
    
    bool check(TreeNode* root){
        if(root==NULL)
            return false;
        
        bool left = check(root->left);
        bool right = check(root->right);
        
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        
        return root->val==1 || left || right;
    }
};