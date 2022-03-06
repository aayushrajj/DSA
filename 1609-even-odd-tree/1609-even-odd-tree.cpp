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
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(depth==0){
                int prev=temp[0];
                if(prev%2==0) return false;
                for(int i=1;i<temp.size();i++){
                    if(temp[i]%2==0 || temp[i]<=prev)
                        return false;
                    prev = temp[i];
                }
            }
            else{
                int prev=temp[0];
                if(prev%2!=0) return false;
                for(int i=1;i<temp.size();i++){
                    if(temp[i]%2!=0 || temp[i]>=prev)
                        return false;
                    prev = temp[i];
                }
            }
            temp.clear();
            depth = !depth;
        }
        return true;
    }
};