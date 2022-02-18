// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.length()-1);
    }
    
    //check palindrome
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    
    //solve function
    int solve(string &str ,int i,int j){
        if(i>=j) return 0;
        if(isPalindrome(str,i,j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int minans=INT_MAX;
        for(int k=i;k<=j-1;k++){
             int temp = 1 + solve(str,i,k) + solve(str,k+1,j);
             minans = min(minans,temp);
        }
        
        return dp[i][j] = minans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends