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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        TreeNode* dummy = new TreeNode();
        temp = dummy;
        inOrder(root,temp);
        return dummy->right;
    }
    
    void inOrder(TreeNode* root , TreeNode* &temp){
        if(root==NULL)
            return;
        inOrder(root->left,temp);
        temp->right = new TreeNode(root->val);
        temp = temp->right;
        inOrder(root->right,temp);
    }
};