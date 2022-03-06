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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int size = q.size();
            int prev = -1;
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                if(depth==0){
                    if(curr->val%2==0) return false;
                    if(curr->val<=prev) return false;
                }
                else{
                    if(curr->val%2!=0) return false;
                    if(prev>0 && curr->val>=prev) return false;
                }
                prev = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            depth = !depth;
        }
        return true;
    }
};