class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return res;
        vector<string> map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s = "";
        comb(digits,map,0,s);
        return res;
    }
    
    void comb(string &digits,vector<string> &map,int idx,string &s){
        if(idx==digits.length()){
            res.push_back(s);
            return;
        }
        for(auto val :  map[digits[idx]-'0'] ){
            s += val;
            comb(digits,map,idx+1,s);
            s.pop_back();
        }
    }
};