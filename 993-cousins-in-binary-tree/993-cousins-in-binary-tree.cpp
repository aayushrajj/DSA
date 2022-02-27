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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y)
            return false;
        int xparent = -1;
        int xdepth = helper(root,xparent,x,0);
        int yparent = -1;
        int ydepth = helper(root,yparent,y,0);
        
        return (xparent!=yparent) && (xdepth==ydepth);
    }
    
    int helper(TreeNode* root,int &parent,int value,int depth){
        if(root==NULL)
            return 0;
        if(root->val==value)
            return depth;
        parent = root->val;
        int left = helper(root->left,parent,value,depth+1);
        if(left)
            return left;
        parent = root->val;
        int right = helper(root->right,parent,value,depth+1);
        return right;
    }
};