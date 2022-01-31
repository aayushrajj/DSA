class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int n = accounts.size();
        int m = accounts[0].size();
        
        for(int i=0;i<n;i++){
            int current = 0;
            for(int j=0;j<m;j++){
                current += accounts[i][j];
            } 
            maxWealth = max(maxWealth,current);
        }
        return maxWealth;
    }
};