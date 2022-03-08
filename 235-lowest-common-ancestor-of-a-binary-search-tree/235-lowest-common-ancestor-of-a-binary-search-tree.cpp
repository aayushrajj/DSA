/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode*> first;
        vector<TreeNode*> second;
        helper(root,p,first);
        helper(root,q,second);
        for(auto i=0;i<first.size();i++){
            for(auto j=0;j<second.size();j++){
                if(first[i]==second[j])
                    return first[i];
            }
        }
        return NULL;
    }
    
    void helper(TreeNode* root,TreeNode* p,vector<TreeNode*> &first){
        if(root==NULL) return;
        if(root==p){
            first.push_back(root);
            return;
        }
        helper(root->left,p,first);
        if(first.size()==0){
            helper(root->right,p,first);
        }
        if(first.size()!=0)
            first.push_back(root);
    }
};