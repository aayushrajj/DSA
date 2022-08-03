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
    int count = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            solve(node,targetSum);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return count;
    }
    
    void solve(TreeNode* root,long long sum){
        if(root==NULL)
            return;
        
        sum -= root->val;
        if(sum==0) count++;
        solve(root->left,sum);
        solve(root->right,sum);
        sum +=  root->val;
        
        return;
    }
};