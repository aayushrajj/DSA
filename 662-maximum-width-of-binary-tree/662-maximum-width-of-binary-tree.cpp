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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int result = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int minn = q.front().second;
            int start,end;
            for(int i=0;i<size;i++){
                pair<TreeNode*,int> curr = q.front();
                int idx = curr.second-minn;
                q.pop();
                if(i==0) start = idx;
                if(i==size-1) end = idx;
                if(curr.first->left)
                    q.push({curr.first->left,(long long)2*idx+1});
                if(curr.first->right)
                    q.push({curr.first->right,(long long)2*idx+2});
            }
            result = max(result,end-start+1);
        }
        return result;
    }
};