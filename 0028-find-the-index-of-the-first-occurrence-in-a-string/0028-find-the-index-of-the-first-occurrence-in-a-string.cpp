class Solution {
public:
    int strStr(string haystack, string needle) {
        int res = -1;
        
        if(haystack.size() < needle.size())
            return res;
        
        int i=0;
        while(i<haystack.size()){
            if(needle[0]==haystack[i]){
                int j=0,k=i;
                while(j<needle.size() && k<haystack.size() && needle[j]==haystack[k]){
                    j++;
                    k++;
                }
                if(j==needle.size())
                    res = i;
            }
            if(res != -1) break;
            i++;
        }
        
        return res;
    }
};