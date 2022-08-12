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
        int count=0,maxFreq=0;
        TreeNode *prev = NULL;
        inOrder(root,prev,count,maxFreq);
        return res;
    }
    
    void inOrder(TreeNode* root,TreeNode* &prev,int &count,int &maxFreq){
        if(root==NULL) return;
        
        inOrder(root->left,prev,count,maxFreq);
        
        if(prev && root->val==prev->val)
            count++;
        else
            count=1;
        if(count==maxFreq)
            res.push_back(root->val);
        if(count>maxFreq){
            res.clear();
            res.push_back(root->val);
            maxFreq = count;
        }
        prev = root;
        
        inOrder(root->right,prev,count,maxFreq);
    }
};