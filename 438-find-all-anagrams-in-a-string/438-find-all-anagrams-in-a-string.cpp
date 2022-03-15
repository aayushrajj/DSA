class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(m>n) return {};
        vector<int> ans;
        vector<int> store(26,0);
        vector<int> check(26,0);
        int i=0,j=0;
        while(j<m){
            store[p[j]-'a']++;
            check[s[j]-'a']++;
            j++;
        }
        if(store==check)
            ans.push_back(i);
        i++;
        while(j<n){
            check[s[j-m]-'a']--;
            check[s[j]-'a']++;
            if(check==store)
                ans.push_back(i);
            i++; j++;
        }
        return ans;
    }
};