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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,temp,targetSum);
        return res;
    }
    
    void solve(TreeNode* root,vector<int> &temp,int sum){
        if(root==NULL) return;
        
        temp.push_back(root->val);
        sum -= root->val;
        
        if(root->left==NULL && root->right==NULL && sum==0)
            res.push_back(temp);
        
        solve(root->left,temp,sum);
        solve(root->right,temp,sum);
        temp.pop_back();
        return;
    }
};