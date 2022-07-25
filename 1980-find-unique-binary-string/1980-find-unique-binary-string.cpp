class Solution {
public:
    string res = "";
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> map;
        for(auto &s : nums)
            map.insert(s);
        
        string curr = "";
        backtrack(map,curr,n);
        
        return res;
    }
    
    void backtrack(unordered_set<string> &map,string &curr,int n){
        if(curr.length()==n){
            if(map.find(curr)==map.end() && res == "")
                res = curr;
            return;    
        }
        
        curr += '1';
        backtrack(map,curr,n);
        curr.pop_back();
        curr += '0' ;
        backtrack(map,curr,n);
        curr.pop_back();
        
        return;
    }
};