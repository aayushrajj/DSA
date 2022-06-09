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
    bool findTarget(TreeNode* root, int k) {
        vector<int> store;
        helper(root,store);
        return twoSum(store,k);
    }
    
    void helper(TreeNode* root,vector<int>&store){
        if(root==NULL)
            return;
        
        helper(root->left,store);
        store.push_back(root->val);
        helper(root->right,store);
    }
    
    bool twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        
        while(low<high){
            if(numbers[low]+numbers[high] == target)
                return true;
            
            if( numbers[low]+numbers[high] > target)
                high--;
            else
                low++;
        }
        
        return false;
    }
};