/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        
        Node* copy = new Node(node->val);
        vector<Node*> visited(1000,NULL);
        visited[node->val] = copy;
        
        for(auto child : node->neighbors){
            if(visited[child->val]==NULL){
                Node* newNode = new Node(child->val);
                (copy->neighbors).push_back(newNode);
                dfs(child,newNode,visited);
            }
            else{
                (copy->neighbors).push_back(visited[child->val]);
            }
        }
        
        return copy;
    }
    
    void dfs(Node* originalNode , Node* copyNode , vector<Node*> &visited){
        visited[copyNode->val] = copyNode;
        
        for(auto child : originalNode->neighbors){
            if(visited[child->val]==NULL){
                Node* newNode = new Node(child->val);
                (copyNode->neighbors).push_back(newNode);
                dfs(child,newNode,visited);
            }
            else{
                (copyNode->neighbors).push_back(visited[child->val]);
            }
        }
    }
};