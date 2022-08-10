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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        TreeNode* root = NULL;
        root = convert(nums,start,end,root);
        return root;
        
    }
    
    // function to fill any node
    TreeNode* getNewNode(int data){
        TreeNode* newNode = new TreeNode;
        newNode->val = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
        
    //function to convert
    TreeNode* convert(vector<int> &a , int start , int end , TreeNode* root){
        if(start > end)
        {
            root = NULL;
        }
        else
        {
            int mid = (start+end)/2;
            root = getNewNode(a[mid]);
            root->left = convert(a,start,mid-1,root->left);
            root->right = convert(a,mid+1,end,root->right);
        }
        return root;
    }
};