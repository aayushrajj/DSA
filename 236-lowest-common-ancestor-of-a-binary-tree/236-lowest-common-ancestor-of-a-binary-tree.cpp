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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
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
    
    void helper(TreeNode* root,TreeNode* val,vector<TreeNode*> &vec){
        if(root==NULL) return;
        if(root==val){
            vec.push_back(root);
            return;
        }
        helper(root->left,val,vec);
        if(vec.size()==0){
            helper(root->right,val,vec);
        }
        if(vec.size()!=0)
            vec.push_back(root);
    }
};