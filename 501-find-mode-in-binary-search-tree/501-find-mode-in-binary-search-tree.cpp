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
    unordered_map<int,int> map;
    vector<int> findMode(TreeNode* root) {
        inOrder(root);
        int mode = INT_MIN;
        for(auto v : map){
            mode = max(mode,v.second);
        }
        vector<int> res;
        for(auto v : map){
            if(v.second==mode)
                res.push_back(v.first);
        }
        return res;
    }
    
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        map[root->val]++;
        inOrder(root->right);
    }
};