// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxlen=0,prefix=0;
        unordered_map<int,int> map;
        for(int i=0;i<N;i++){
            prefix += A[i];
            if(prefix==K){
                maxlen = i+1;
            }
            if(map.find(prefix)==map.end()){
                map.insert({prefix,i});
            }
            if(map.find(prefix-K)!=map.end()){
                maxlen = max(maxlen,i-map[prefix-K]);
            }
        }
        return maxlen;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends