class Solution {
public:
    int pal[101][101];
    int dp[101][101];
    int palindromePartition(string s, int k) {
        int n = s.length();
        memset(pal,0,sizeof(pal));
        memset(dp,-1,sizeof(dp));
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    pal[i][j]=0;
                else if(g==1){
                    if(s[i]==s[j])
                        pal[i][j]=0;
                    else
                        pal[i][j]=1;
                }
                else{
                    if(s[i]==s[j])
                        pal[i][j] = pal[i+1][j-1];
                    else
                        pal[i][j] = 1 + pal[i+1][j-1];
                }
            }
        }
        
        return findMinCost(0,k,n);
    }
    
    int findMinCost(int index,int k,int n){
        if(index==n)
            return n;
        if(k==1)
            return pal[index][n-1];
        if(dp[index][k]!=-1)
            return dp[index][k];
        int ans = INT_MAX;
        for(int i=index;i<n;i++){
            ans = min(ans , pal[index][i] + findMinCost(i+1,k-1,n));
        }
        return dp[index][k] = ans;
    }
};