class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> map;
        for(auto v : arr)
            map[v]++;
        for(auto v  : arr){
            if(map[v]==1){
                k--;
                if(k==0)
                    return v;
            }
        }
        return "";
    }
};