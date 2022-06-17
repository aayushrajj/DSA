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
    // int camera=0;
    enum Camera { no_need , no_camera , has_camera};
    int count=0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==no_camera)
            count++;
        return count;
    }
    
    Camera dfs(TreeNode* root){
        if(root==NULL)
            return no_need;
        Camera left = dfs(root->left);
        Camera right = dfs(root->right);
        if(left==no_camera|| right==no_camera){
            count++;
            return has_camera;
        }
        else if(left==has_camera || right==has_camera)
            return no_need;
        else
            return no_camera;   
    }
};