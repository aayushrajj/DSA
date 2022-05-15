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
    int maxdeep = 0;
    int sum = 0;
    int deepestLeavesSum(TreeNode* root) {
        maxdeep = maxdepth(root);
        deepest(root,1);
        return sum;
    }
    
    int maxdepth(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);
        return 1 + max(left,right); 
    }
    
    void deepest(TreeNode* root,int depth){
        if(root==NULL)
            return;
        deepest(root->left,depth+1);
        deepest(root->right,depth+1);
        if(depth==maxdeep)
            sum += root->val;
    }
};