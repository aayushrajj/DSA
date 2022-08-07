class Solution {
public:
    bool isPalindrome(string s) {
        string copy = "";
        for(auto &c : s){
            if(c>='A' && c<='Z')
                c = c+32;
            if(c>='a' && c<='z')
                copy += c;
            if(c>='0' && c<='9')
                copy += c;
        }
        int len = copy.length();
        int i=0,j=len-1;
        while(i<j){
            if(copy[i]!=copy[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};