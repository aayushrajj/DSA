class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        int window = p.size();
        int len = s.size();
        
        if(window>len)
            return ans;
        int left =0 , right=0;
        while(right<window){
            phash[p[right]-'a']++;
            shash[s[right]-'a']++;
            right++;
        }
        right--;
        while(right<len){
            if(phash==shash)
                ans.push_back(left);
            right++;
            if(right!=len)
                shash[s[right]-'a']++;
            shash[s[left]-'a']--;
            left++;
        }
        return ans;      
    }
};