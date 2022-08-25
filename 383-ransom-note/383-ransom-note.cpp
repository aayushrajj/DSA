class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag;
        unordered_map<char,int> ran;
        for(auto c : magazine)
            mag[c]++;
        for(auto c : ransomNote)
            ran[c]++;
        
        for(auto c : ransomNote)
            if(mag[c]<ran[c])
                return false;
        
        return true;
        
    }
};