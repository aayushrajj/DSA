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
    int ans = INT_MAX;
    TreeNode* prev = NULL;
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return ans;
    }
    
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        if(prev)
            ans = min(ans , root->val - prev->val);
        prev = root;
        inOrder(root->right);
    }
};