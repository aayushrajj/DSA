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
    bool isValidBST(TreeNode* root) {
        vector<int> store;
        inOrder(root,store);
        for(int i=0;i<store.size()-1;i++){
            if(store[i]>=store[i+1])
                return false;
        }
        return true;
    }
    
    void inOrder(TreeNode* root , vector<int> &store){
        if(root==NULL)
            return;
        inOrder(root->left,store);
        store.push_back(root->val);
        inOrder(root->right,store);
    }
};