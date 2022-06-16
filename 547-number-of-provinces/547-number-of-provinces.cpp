class Solution {
public:
    //union find
    int findCircleNum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ranks(n,0);
        
        // every city is connected to itself
        for(int i=0;i<n;i++){
            ranks[i] = i;
        }
        
        int groups = n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(matrix[i][j]){
                    int rootI = find(i,ranks);
                    int rootJ = find(j,ranks);
                    if(rootI != rootJ){
                        ranks[rootI] = rootJ;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

    int find(int x,vector<int> &parents){
        if(x!=parents[x])
            parents[x] = find(parents[x],parents);
        return parents[x];
    }
};