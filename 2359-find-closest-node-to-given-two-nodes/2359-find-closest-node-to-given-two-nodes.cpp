class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> visited(n,0);
        
        vector<int> dist1(n,-1);
        vector<int> dist2(n,-1);
        
        int d = 0;
        dfs(edges,visited,dist1,node1,n,d);
        
        d = 0;
        fill(visited.begin(),visited.end(),0);
        dfs(edges,visited,dist2,node2,n,d);
        
        int curr = INT_MAX;
        int resIdx = -1;
        for(int i=0;i<n;i++){
             if(dist1[i]!=-1 && dist2[i]!=-1){
                 int t = max(dist1[i],dist2[i]);
                 if(t < curr){
                     curr = t;
                     resIdx = i;
                 }
             }
        }
        
        return resIdx;
    }
    
    void dfs(vector<int>& edges,vector<int>& visited,vector<int>& dist,int node,int n,int d){
        visited[node] = 1;
        dist[node] = d;
        if(node < n && edges[node]!=-1 && edges[node] <  n && visited[edges[node]]==0)
            dfs(edges,visited,dist,edges[node],n,d+1);
        return;
    }
};