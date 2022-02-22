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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        return check(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    
    bool check(TreeNode* p,TreeNode* q){
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        if(p->val==q->val)
            return check(p->left,q->left) && check(p->right,q->right);
        else
            return false;
        
    }
};