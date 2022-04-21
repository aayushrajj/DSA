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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        curr++;
        return vec[curr-1];
    }
    
    bool hasNext() {
        if(curr < vec.size())
            return true;
        else
            return false;
    }
    
private:
    void inOrder(TreeNode* root){
        if(root==NULL) return;
        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }
    vector<int> vec;
    int curr = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */