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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int check = root->val;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val!=check)
                return false;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return true;
    }
};