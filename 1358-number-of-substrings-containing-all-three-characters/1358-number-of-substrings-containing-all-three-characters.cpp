class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        unordered_map<char,int> map;
        int i=0,j=0;
        int total=0;
        while(j<n){
            map[s[j]-'a']++;
            if(map['a'-'a']>=1 && map['b'-'a']>=1 && map['c'-'a']>=1){
                while(map['a'-'a']>=1 && map['b'-'a']>=1 && map['c'-'a']>=1){
                    total += n-j;
                    map[s[i]-'a']--;
                    i++;
                }
            }
            j++;
        }
        return total;
    }
};