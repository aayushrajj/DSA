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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL)
            return vec;
        helper(root,0,vec);
        return vec;
    }
    
    void helper(TreeNode* root,int depth,vector<vector<int>> &vec){
        if(root==NULL)
            return;
        if(depth>=vec.size())
            vec.push_back({});
        vec[depth].push_back(root->val);
        helper(root->left,depth+1,vec);
        helper(root->right,depth+1,vec);
    }
};