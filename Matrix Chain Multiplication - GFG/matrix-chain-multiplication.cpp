// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[]){
        int dp[N][N];
        for(int g=0;g<N-1;g++){
            for(int i=0,j=g;j<N-1;i++,j++){
                if(g==0){
                    dp[i][j] = 0;
                }
                else if(g==1){
                    dp[i][j] = arr[i]*arr[j+1]*arr[j];
                }
                else{
                    int mincost = INT_MAX;
                    for(int k=i;k<=j-1;k++){
                        int leftcost = dp[i][k];
                        int rightcost = dp[k+1][j];
                        int m = arr[i]*arr[j+1]*arr[k+1];
                        int totalcost = leftcost+rightcost+m;
                        
                        mincost = min(mincost,totalcost);
                    }
                    dp[i][j] = mincost;
                }
            }
        }
        return dp[0][N-2];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends