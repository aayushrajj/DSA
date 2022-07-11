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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        
        vector<int> view;
        dfs(root,view,0);
        return view;
    }
    
    void dfs(TreeNode* root,vector<int> &view,int level){
        if(root==NULL)
            return;
        if(level==view.size())
            view.push_back(root->val);
        if(root->right)
            dfs(root->right,view,level+1);
        if(root->left)
            dfs(root->left,view,level+1);
    }
};