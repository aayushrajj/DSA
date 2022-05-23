class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open =0 , close =0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                open++;
            else if(s[i]=='*')
                open++;
            else
                open--;
            if(open<0)
                return false;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]==')')
                close++;
            else if(s[i]=='*')
                close++;
            else
                close--;
            
            if(close<0)
                return false;
        }
        return true;
    }
};