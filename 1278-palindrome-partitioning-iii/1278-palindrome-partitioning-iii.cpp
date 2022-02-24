class Solution {
public:
    long int count(string s,int l,int r){
        long int c=0;
        while(l<r){
            if(s[l]!=s[r]) c++;
            l++;
            r--;
        }
        return c;
    }
    
    int dp[101][101];
    int solve(string s,int k,int i){
        if(i==s.length() and k==0) return 0;
        if(k<0||i>=s.length()) return INT_MAX;
        long int ans=INT_MAX;
        if(dp[i][k]!=-1) return dp[i][k];
        for(int j=i;j<s.length();j++){
            ans=min(ans,count(s,i,j)+solve(s,k-1,j+1));
        }
        return dp[i][k]=ans;
    }
    
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,k,0);
    }
};