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
    long long total = 0;
    long long product = 0;
    int maxProduct(TreeNode* root) {
        int mod = 1e9 + 7;
        inOrder(root);
        
        long long temp = helper(root);
        
        return product%mod;
    }
    
    //calculating total sum
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        total += root->val;
        inOrder(root->right);
    }
    
    //helper
    long long helper(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftSide = helper(root->left);
        product = max( (total-leftSide)*leftSide , product);
        
        int rightSide = helper(root->right);
        product = max( (total-rightSide)*rightSide , product);
        
        return leftSide + rightSide + root->val;
    }
};