// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> dp(n,0);
       dp[0] = 1;
       int overallmax = 0;
       for(int i=0;i<n;i++){
           int maxpreviously = 0;
           for(int j=0;j<i;j++){
               if(a[j]<a[i]){
                   maxpreviously = max(maxpreviously , dp[j]);
               }
           }
           dp[i] = 1 + maxpreviously;
           overallmax = max(overallmax,dp[i]);
       }
       return overallmax;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends