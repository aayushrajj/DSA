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
    int count=0;
    int goodNodes(TreeNode* root) {
        TreeNode* prev = root;
        traverse(root,prev);
        return count;
    }
    
    void traverse(TreeNode* root,TreeNode* prev){
        if(root==NULL) return;
        
        if(root->val >= prev->val){
            count++;
            prev = root;
        }
        
        traverse(root->left,prev);
        traverse(root->right,prev);
        
        return;
    }
    
};