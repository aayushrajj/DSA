class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> grayString = generate(n);
        vector<int> res;
        for(auto i : grayString){
            res.push_back(stoi(i,0,2));
        }
        return res;
    }
    
    vector<string> generate(int n){
        if(n==1)
            return {"0","1"};
        
        vector<string> temp = generate(n-1);
        vector<string> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
};