class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> currList;
        dfs(s,0,currList);
        return ans;
    }
    
    bool isPlaindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++; end--;
        }
        return true;
    }
    
    void dfs(string &s,int start,vector<string> &currList){
        if(start>=s.length()){
            ans.push_back(currList);
            return;
        }
        for(int end=start;end<s.length();end++){
            if(isPlaindrome(s,start,end)){
                currList.push_back(s.substr(start,end-start+1));
                dfs(s,end+1,currList);
                currList.pop_back();
            }
        }
        return;
    }
};