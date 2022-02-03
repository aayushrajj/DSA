class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        int window = s1.size();
        int len = s2.size();
        if(window>len)
            return false;
        int left = 0 , right = 0;
        while(right<window){
            hash1[s1[right]-'a']++;
            hash2[s2[right]-'a']++;
            right++;
        }
        right--;
        while(right<len){
            if(hash1==hash2)
                return true;
            right++;
            if(right!=len)
                hash2[s2[right]-'a']++;
            hash2[s2[left]-'a']--;
            left++;
        }
        return false;
    }
};