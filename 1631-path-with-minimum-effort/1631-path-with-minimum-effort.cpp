typedef tuple<int,int,int> ti;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> effort(n,vector<int> (m,INT_MAX));
        // int effort[n][m];
        // memset(effort,INT_MAX,sizeof(effort));
        
        vector<vector<int>> dir = {{0,1} , {0,-1} , {1,0} , {-1,0}};
        priority_queue<ti , vector<ti> , greater<ti> > pq;
        pq.push({0,0,0}); // dist-row-col
        
        while(!pq.empty()){
            auto [dist,row,col] = pq.top();
            pq.pop();
            
            if(dist > effort[row][col]) continue;
            if(row == n-1 && col == m-1) return dist;
            
            for(auto d : dir){
                int newrow = row + d[0];
                int newcol = col + d[1];
                
                if(newrow >= 0 && newrow < n && newcol >=0 && newcol < m){
                    int newDist = max( dist , abs(heights[newrow][newcol] - heights[row][col]) );
                    if(effort[newrow][newcol] > newDist){
                        effort[newrow][newcol] = newDist;
                        pq.push({newDist , newrow , newcol});
                    }
                }
            }
        }
        return 0;
    }
};