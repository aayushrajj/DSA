class Solution {
public:
    int m,n;
    vector<vector<int>> dir { {0,1},{0,-1},{1,0},{-1,0} };
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        
        vector<vector<int>> groups;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    int endi = i , endj = j;
                    explore(land,i,j,endi,endj);
                    groups.push_back({i,j,endi,endj});
                }
            }
        }
        
        return groups;
    }
    
    
    void explore(vector<vector<int>> &land,int row,int col,int &endi,int &endj){
        for(auto &d : dir){
            int newrow = row + d[0];
            int newcol = col + d[1];
            if(newrow>=0 && newrow<m && newcol>=0 && newcol<n){
                if(land[newrow][newcol]==1){
                    endi = max(endi,newrow);
                    endj = max(endj,newcol);
                    land[newrow][newcol] = 0;
                    explore(land,newrow,newcol,endi,endj);       
                }
            }
        }
    }
};