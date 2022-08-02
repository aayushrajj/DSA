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
    int sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        int temp = solve(root);
        return sum;
    }
    
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        int max1 = max(root->val , root->val + max(left,right) );
        int max2 = max(max1 , root->val + left + right);
        sum = max(sum,max2);
        
        return max1;
    }
};