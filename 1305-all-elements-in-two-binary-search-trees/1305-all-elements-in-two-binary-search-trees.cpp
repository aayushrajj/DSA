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
        inOrder(root1,list);
        inOrder(root2,list);
        
        sort(list.begin(),list.end());
        return list;
    }
    
    void inOrder(TreeNode* root , vector<int> &list){
        if(root==NULL)
            return;
        inOrder(root->left,list);
        list.push_back(root->val);
        inOrder(root->right,list);
    }
};