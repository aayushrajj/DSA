class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s,0,curr);
        return res;
    }
    
    bool is_pal(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void dfs(string &s,int start,vector<string> &curr){
        if(start>=s.length()){
            res.push_back(curr);
            return;
        }
        
        for(int i=start;i<s.length();i++){
            if(is_pal(s,start,i)){
                curr.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,curr);
                curr.pop_back();
            }
        }
        return;
    }
};