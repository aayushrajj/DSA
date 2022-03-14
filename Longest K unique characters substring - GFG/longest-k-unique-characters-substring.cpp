// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        unordered_map<char,int> visited;
        int i=0,j=0;
        int size=-1;
        while(j<n){
            visited[s[j]]++;
            if(visited.size()<k){
                j++;
            }
            else if(visited.size()>k){
                while(visited.size()>k){
                    visited[s[i]]--;
                    if(visited[s[i]]==0){
                        visited.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            else if(visited.size()==k){
                size = max(size,j-i+1);
                j++;
            }
        }
        return size;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends