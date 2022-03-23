class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n&1)
            res.push_back(0);
        int i=1;
        while(res.size()<n){
            res.push_back(i);
            res.push_back(-i);
            i++;
        }
        return res;
    }
};