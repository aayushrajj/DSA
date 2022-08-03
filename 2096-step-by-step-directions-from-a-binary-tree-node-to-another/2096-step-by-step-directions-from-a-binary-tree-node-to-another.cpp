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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = helper(root,startValue,destValue);
        
        string lca_to_start = "";
        string lca_to_dest = "";
        
        traverse(lca,startValue,lca_to_start);
        traverse(lca,destValue,lca_to_dest);
        
        for(auto &c : lca_to_start)
            c = 'U';
        
        return lca_to_start + lca_to_dest;
    }
    
    bool traverse(TreeNode* root,int p,string &path){
        if(root==NULL) return false;
        if(root->val==p) return true;
        
        path += 'L';
        if(traverse(root->left,p,path)) return true;
        path.pop_back();
        
        path += 'R';
        if(traverse(root->right,p,path)) return true;
        path.pop_back();
        
        return false;
    }
    
    
    TreeNode* helper(TreeNode* root,int p,int q){
        if(root==NULL)
            return NULL;
        if(root->val==p || root->val==q)
            return root;
        
        TreeNode* left = helper(root->left,p,q);
        TreeNode* right = helper(root->right,p,q);
        
        if(left && right)
            return root;
        
        return left==NULL ? right : left;
    }
};