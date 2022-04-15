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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<string> sStr;
        stack<TreeNode*> sNode;
        if(root==NULL)
            return res;
        sNode.push(root);
        sStr.push(to_string(root->val));
        while(!sNode.empty()){
            TreeNode* curr = sNode.top(); sNode.pop();
            string currStr = sStr.top(); sStr.pop();
            if(curr->left==NULL && curr->right==NULL){
                res.push_back(currStr);
                continue;
            }
            if(curr->left!=NULL){
                sNode.push(curr->left);
                sStr.push(currStr + "->" + to_string(curr->left->val));
            }
            if(curr->right!=NULL){
                sNode.push(curr->right);
                sStr.push(currStr + "->" + to_string(curr->right->val));
            }
        }
        return res;
    }
};