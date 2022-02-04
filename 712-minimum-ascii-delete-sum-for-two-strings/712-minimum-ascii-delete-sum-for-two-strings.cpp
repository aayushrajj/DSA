class Solution {
public:
    vector<vector<int>> dp;
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        dp = vector<vector<int>> (m+1,vector<int> (n+1,-1));
        
        return helper(s1,s2,0,0);   

    }
    
    //add ASCII sum
    int addASCII(string& a , int i){
        int sum = 0;
        for(;i<a.size();i++){
            sum += (int)a[i];
        }
        return sum;
    }
    
    //helper function
    int helper(string &a , string &b , int i , int j){
        int m = a.size();
        int n = b.size();
        int total = 0;
        
        if(i==m || j==n){
            if(i==m && j==n)
                return 0;
            return i==m ? addASCII(b,j) : addASCII(a,i);
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i]==b[j])
            total = helper(a,b,i+1,j+1);
        else
            total = min( (int)a[i] + helper(a,b,i+1,j) , (int)b[j] + helper(a,b,i,j+1));
        
        dp[i][j] = total;
        return total;      
    }
};