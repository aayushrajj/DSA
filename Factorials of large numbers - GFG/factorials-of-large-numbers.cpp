// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(N);
        int carry = 0;
        for(int i=N-1;i>=2;i--){
            carry = 0;
            for(int j=ans.size()-1;j>=0;j--){
                ans[j] = ans[j]*i + carry;
                carry = ans[j]/10;
                ans[j] = ans[j]%10;
            }
            while(carry){
                ans.insert(ans.begin(),carry%10);
                carry = carry/10;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends