typedef pair<int , pair<int,int>> pi;
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<int> dir={0,1,0,-1,0};
        vector<vector<int>> dist(m, vector<int> (n,INT_MAX));
        dist[0][0]=0;
        priority_queue<pi , vector<pi> , greater<pi> > pq;
        pq.push({0,{0,0}}); // {cost , {row ,col}}
        while(!pq.empty())
        {
            auto v=pq.top();
            pq.pop();
            int i=v.second.first, j=v.second.second, d=v.first;
            for(int k=0;k<4;k++)
            {
                int x=i+dir[k], y=j+dir[k+1];
                if(x<0 || x>=m || y<0 || y>=n) continue;
                
                if(d+grid[x][y]<dist[x][y])
                {
                    dist[x][y]=d+grid[x][y];
                    pq.push({dist[x][y],{x,y}});
                }
            }
        }
        return dist[m-1][n-1];  
    }
};