class Solution {
public:
    int dp[2001][2001];
    int minCut(string s){
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
    
    bool isPalindrome(string &s,int start,int end){
        while(end>start){
            if(s[start]!=s[end])
                return false;
            start++; end--;
        }
        return true;
    }
    
    int solve(string& s,int i,int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if((isPalindrome(s,i,j)))
            return 0;
        int minans = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(isPalindrome(s,i,k)){
                int temp = solve(s,i,k) + solve(s,k+1,j) + 1;
                minans = min(minans,temp);
            }    
        }
        return dp[i][j] = minans;
    }
};