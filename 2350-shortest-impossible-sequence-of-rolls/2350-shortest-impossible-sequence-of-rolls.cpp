class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int res = 1;
        unordered_set<int> map;
        for(auto &s : rolls){
            map.insert(s);
            if(map.size()==k){
                res++;
                map.clear();
            }
        }
        
        return res;
    }
};