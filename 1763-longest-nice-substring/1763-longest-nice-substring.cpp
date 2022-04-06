class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        int maxlength=0;
        string result;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isNice(s,i,j)){
                    if(j-i+1>maxlength){
                        maxlength = j-i+1;
                        result = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return result;
    }
    
    bool isNice(string &s,int i,int j){
        unordered_map<int,bool> map;
        for(int x=i;x<=j;x++){
            map[s[x]] = true;
        }
        while(i<=j){
            // if char is UPPERCASE
            if(s[i]<97){
                if(map[s[i]+32]==false)
                    return false;
            }
            // IF CHAR IS LOWERCASE
            else{
                if(map[s[i]-32]==false)
                    return false;
            }
            i++;
        }
        return true;
    }
};