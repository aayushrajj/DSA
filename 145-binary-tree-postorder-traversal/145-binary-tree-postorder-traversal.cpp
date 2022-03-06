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
        TreeNode* last = NULL;
        while(root || !s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                TreeNode* curr = s.top();
                if(curr->right && last!=curr->right){
                    root = curr->right;
                }
                else{
                    res.push_back(curr->val);
                    last = curr;
                    s.pop();
                }
            }
        }
        return res;
    }
};