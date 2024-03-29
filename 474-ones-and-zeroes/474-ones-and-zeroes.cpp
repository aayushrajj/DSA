class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        memset(dp,-1,sizeof(dp));
        unordered_map<int,pair<int,int>> map;
        for(int i=0;i<len;i++){
            int size = strs[i].length();
            int ones =0 , zeros = 0;
            for(int j=0;j<size;j++){
                if(strs[i][j]=='0')
                    zeros++;
                else
                    ones++;
            }
            map[i] = {zeros,ones};
        }
        return helper(strs,m,n,map,len,0);
    }
    
    int helper(vector<string> &strs,int m,int n,unordered_map<int,pair<int,int>> &map,int last,int i){
        if(i>=last || (m==0 && n==0))
            return 0;
        if(dp[i][m][n]!=-1)
            return dp[i][m][n];
        
        int op1=0,op2=0;
        int zeros = map[i].first;
        int ones = map[i].second;
        
        if(zeros<=m && ones<=n){
            op1 = 1 + helper(strs,m-zeros,n-ones,map,last,i+1);
        }
        op2 = helper(strs,m,n,map,last,i+1); 
        return dp[i][m][n] = max(op1,op2);
    }
};