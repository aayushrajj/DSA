class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.length();
        int i=0,j=n-1;
        while(i<j){
            if( isalpha(s[i])!=0 && isalpha(s[j])!=0 ){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++; j--;
            }
            else if(isalpha(s[i])!=0)
                j--;
            else
                i++;
        }
        return s;
    }
};