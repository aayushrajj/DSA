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
    
    //tech dose video best explaination
    int max1=0; int max2=0; int result=INT_MIN;
    int maxPathSum(TreeNode* root) {
        int temp = postOrder(root);
        return result;
    }
    
    int postOrder(TreeNode *root){
        if(root==NULL)
            return 0;
        int left = postOrder(root->left);
        int right = postOrder(root->right);
        
        max1 = max( root->val , max(left,right) + root->val );
        max2 = max( max1 , root->val + left + right);
        result = max( max2 , result);
        
        return max1;
    }
};