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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* newroot = NULL;
        find(root,val,newroot);
        return newroot;
    }
    
    void find(TreeNode* root,int val,TreeNode* &newroot){
        if(root==NULL)
            return;
        if(root->val==val){
            newroot = root;
            return;
        }
        find(root->left,val,newroot);
        find(root->right,val,newroot);
    }
};