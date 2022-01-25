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
    int countNodes(TreeNode* root) {
        return countTree(root);
    }
    
    //countleftheight
    int leftHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        return leftHeight(root->left) + 1;
    }
    
    //countrightheight
    int rightHeight(TreeNode* root){
        if(root==NULL)
            return 0;
        return rightHeight(root->right) + 1;
    }
    
    //count nodes
    int countTree(TreeNode* root){
        if(root==NULL)
            return 0;
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        
        if(lh==rh)
            return pow(2,lh)-1;
        
        return countTree(root->left) + countTree(root->right) + 1;
    }
};