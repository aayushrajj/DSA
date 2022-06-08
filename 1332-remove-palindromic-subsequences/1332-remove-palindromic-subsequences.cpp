class Solution {
public:
    int removePalindromeSub(string s) {
        int low = 0;
        int high = s.length()-1;
        while(low<high){
            if(s[low]!=s[high])
                return 2;
            low++;
            high--;
        }
        return 1;
    }
};