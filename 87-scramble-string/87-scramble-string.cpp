class Solution {
public:
    unordered_map<string,bool> dp;
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        
        vector<int> count(26, 0);
        for(int i=0;i<s1.length();i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0)
                return false;
        }
        
        return solve(s1,s2); 
    }
    
    bool solve(string a,string b){
        string key = a + "_" + b;
        if(a==b)
            return dp[key] = true;
        if(a.length()<=1 || b.length()<=1)
            return false;
        if(dp.find(key)!=dp.end())
            return dp[key];
        
        bool flag = false;
        int n = a.length();
        for(int i=1;i<=n-1;i++){
            bool cond1 = solve(a.substr(0,i),b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));
            bool cond2 = solve(a.substr(0,i),b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
            
            if(cond1 || cond2){
                flag = true;
                break;
            }
        }
        
        return dp[key] = flag;
    }
};