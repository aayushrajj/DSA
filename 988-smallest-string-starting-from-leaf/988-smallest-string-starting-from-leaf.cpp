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
    string res = "~";
    string smallestFromLeaf(TreeNode* root) {
        string temp = "";
        dfs(root,temp);
        return res;
    }
    
    void dfs(TreeNode* root,string s){
        if(root==NULL) return;
        s += root->val+97;
        if(root->left==NULL && root->right==NULL){
            reverse(s.begin(),s.end());
            if(s.compare(res)<0)
                res = s;
            return;
        }
        dfs(root->left,s);
        dfs(root->right,s);
        s.pop_back();
        return;
    }
};