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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list;
        preOrder(root1,list);
        preOrder(root2,list);
        
        sort(list.begin(),list.end());
        return list;
    }
    
    void preOrder(TreeNode* root , vector<int> &list){
        if(root==NULL)
            return;
        list.push_back(root->val);
        preOrder(root->left,list);
        preOrder(root->right,list);
    }
};