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
    int res = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = solve(root);
        return res-1;
    }
    
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        
        int currDiameter = 1 + left + right;
        res = max(res , currDiameter);
        
        return 1 + max(left,right);
    }
};