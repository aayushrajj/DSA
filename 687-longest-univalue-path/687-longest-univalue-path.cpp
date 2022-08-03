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
    int ans;
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        int temp = solve(root);
        return ans;
    }
    
    int solve(TreeNode* root){
        if(root==NULL)
            return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        int leftV =0 , rightV = 0;
        if(root->left && root->left->val==root->val)
            leftV += 1 + left;
        if(root->right && root->right->val==root->val)
            rightV += 1 + right;
        
        ans = max(ans,leftV + rightV);
        
        return max(leftV,rightV);
    }
};