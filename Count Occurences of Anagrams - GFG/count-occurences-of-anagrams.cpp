// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    int n = txt.length();
	    int m = pat.length();
	    int count=0;
	    if(m>n) return 0;
	    vector<int> store(25,0);
	    vector<int> check(25,0);
	    for(int i=0;i<m;i++){
	        store[pat[i]-'a']++;
	        check[txt[i]-'a']++;
	    }
	    if(store==check) count++;
	    for(int i=m;i<n;i++){
	        check[txt[i-m]-'a']--;
	        check[txt[i]-'a']++;
	        if(check==store) count++;
	    }
	    return count;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends