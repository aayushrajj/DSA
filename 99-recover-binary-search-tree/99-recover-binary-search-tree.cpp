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
    TreeNode* first = NULL;
    TreeNode* sec = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(first->val,sec->val);
    }
    
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        if(first==NULL && prev->val > root->val)
            first = prev;
        if(first!=NULL && prev->val > root->val)
            sec = root;
        prev = root;
        inOrder(root->right);
    }
};