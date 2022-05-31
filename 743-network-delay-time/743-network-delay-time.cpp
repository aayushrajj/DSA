class Solution {
public:
    struct node{
        int dest;
        int wt;
    };
    struct qnode{
        int vertex;
        int dist;
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map< int,vector<node*> > adj;
        for(int i=0;i<times.size();i++){
            node *newnode = new node;
            newnode->dest = times[i][1];
            newnode->wt = times[i][2];
            adj[times[i][0]].push_back(newnode);
        }
        
        qnode *newqnode = new qnode;
        newqnode->vertex = k;
        newqnode->dist = 0;
        queue<qnode*> q;
        q.push(newqnode);
        
        
        vector<int> distance(n+1,INT_MAX);
        distance[k] = 0;
        while(!q.empty()){
            qnode *curr = q.front();
            q.pop();
            for(auto it :  adj[curr->vertex]){
                qnode *temp = new qnode;
                temp->vertex = it->dest;
                temp->dist = it->wt + curr->dist;
                if(distance[temp->vertex] > temp->dist){
                    distance[temp->vertex] = temp->dist;
                    q.push(temp);
                }
            }
        }
        
        int minTime = INT_MIN;
        for(int i=1;i<=n;i++){
            minTime = max(minTime , distance[i]);
        }
        
        return minTime == INT_MAX ? -1 : minTime;
    }
};