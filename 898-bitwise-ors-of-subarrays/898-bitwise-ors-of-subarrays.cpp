class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> res , curr , curr2;
        for(auto i : arr){
            curr2 = {i};
            for(auto j : curr)
                curr2.insert(i|j);
            curr = curr2;
            for(auto j : curr2)
                res.insert(j);
        }
        
        return res.size();
    }
};