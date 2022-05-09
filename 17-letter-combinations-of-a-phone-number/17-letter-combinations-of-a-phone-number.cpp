class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return res;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string s = "";
        comb(digits,map,0,s);
        return res;
    }
    
    void comb(string digits,string map[],int idx,string s){
        if(idx==digits.length()){
            res.push_back(s);
            return;
        }
        string val = map[digits[idx]-'0'];
        for(int i=0;i<val.length();i++){
            comb(digits,map,idx+1,s+val[i]);
        }
    }
};