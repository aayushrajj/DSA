class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int left=0,right=n-1;
        while(left<right){
            if(s[left]!=s[right]){
                return (checkPal(s,left,right-1) || checkPal(s,left+1,right));
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool checkPal(string s , int i , int r){
        while(i<r){
            if(s[i]!=s[r])
                return false;
            i++;
            r--;
        }
        return true;
    }
};