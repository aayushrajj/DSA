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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            if(root){
                s.push(root);
                res.insert(res.begin(),root->val);
                root = root->right;
            }
            else{
                TreeNode* curr = s.top();
                s.pop();
                root = curr->left;
            }
        }
        return res;
    }
};