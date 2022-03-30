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
    int findTilt(TreeNode* root) {
        int total=0;
        int temp = tilt(root,total);
        return total;
    }
    
    int tilt(TreeNode* root,int &total){
        if(root==NULL)
            return 0;
        int left = tilt(root->left,total);
        int right = tilt(root->right,total);
        total += abs(left-right);
        return left+right+root->val;
    }
};