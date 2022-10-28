class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> map;
        for(auto word : wordDict)
            map.insert(word);
        
        vector<bool> dp(n+1,false);
        dp[0] = true;
        
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                string curr = s.substr(j,i-j+1); // pso , no of char
                if(map.find(curr)!=map.end())
                    dp[i+1] = dp[j];
                
                if(dp[i+1]) //we found a dict word so move on 
                    break;
            }
        }
        
        return dp[n];
    }
};