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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return res;
        string path = "";
        path += to_string(root->val);
        solve(root,path);
        return res;
    }
    
    void solve(TreeNode* root,string path){
        if(root->left==NULL && root->right==NULL){
            res.push_back(path);
            return;
        }
        if(root->left!=NULL)
            solve(root->left , path + "->" + to_string(root->left->val) );
        if(root->right!=NULL)
            solve(root->right , path + "->" + to_string(root->right->val) );
        return;
    }
};