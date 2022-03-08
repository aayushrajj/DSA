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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp;
        TreeNode* dummy = new TreeNode();
        temp = dummy;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }
            else{
                TreeNode* curr = st.top();
                st.pop();
                root = curr->right;
                curr->left = NULL;
                temp->right = new TreeNode(curr->val); 
                temp = temp->right;
            }
        }
        return dummy->right;
    }
};