/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL) return {};
        vector<vector<int>> res;
        helper(root,res,0);
        return res;
    }
    
    void helper(Node* root,vector<vector<int>> &res,int depth){
        if(root==NULL)
            return;
        if(depth==res.size())
            res.push_back({});
        res[depth].push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            helper(root->children[i],res,depth+1);
        }
    }
};