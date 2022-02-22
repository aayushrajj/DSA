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
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        int count=0,maxfreq=0;
        TreeNode* prev = NULL;
        inOrderFill(root,prev,count,maxfreq);
        return res;
    }
    
    void inOrderFill(TreeNode* root,TreeNode* &prev,int &count,int &maxfreq){
        if(root==NULL)
            return;
        inOrderFill(root->left,prev,count,maxfreq);
        if(prev && prev->val==root->val)
            count++;
        else
            count = 1;
        if(count==maxfreq)
            res.push_back(root->val);
        if(count>maxfreq){
            res.clear();
            res.push_back(root->val);
            maxfreq = count;
        }
        prev = root;
        inOrderFill(root->right,prev,count,maxfreq);
    }
};