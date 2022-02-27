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
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            bool xfound = false;
            bool yfound = false;
            int i=0;
            while(i<size){
                TreeNode* current = q.front();
                q.pop();
                if(current->val==x) xfound = true;
                if(current->val==y) yfound = true;
                if(current->left && current->right){
                    if(current->left->val==x && current->right->val==y
                      || current->left->val==y && current->right->val==x)
                        return false;
                }
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                i++;
            }
            if(xfound && yfound)
                return true;
        }
        return false;
    }
};