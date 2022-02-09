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
    vector<int> store;
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return store[k-1];
    }
    
    void inOrder(TreeNode* root){
        if(root==NULL)
            return;
        inOrder(root->left);
        store.push_back(root->val);
        inOrder(root->right);
    }
};