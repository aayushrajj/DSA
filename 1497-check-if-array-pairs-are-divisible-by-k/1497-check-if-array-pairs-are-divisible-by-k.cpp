class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> map;
        for(int e : arr){
            int rem = e%k;
            int complimentOne = -rem;
            int complimentTwo = (rem<0) ? -k-rem : k-rem;
            
            if(map[complimentOne])
                map[complimentOne]--;
            else if(map[complimentTwo])
                map[complimentTwo]--;
            else
                map[rem]++;
        }
        for(auto e : map){
            if(e.second)
                return false;
        }
        return true;      
    }
};