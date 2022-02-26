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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root==NULL)
            return vec;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp; int i=0;
            while(i<size){
                TreeNode* current = q.front();
                temp.push_back(current->val);
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
                i++;
            }
            vec.push_back(temp);
        }
        return vec;
    }
};