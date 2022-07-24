class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int mod=0;
        for(auto n : nums)
            mod = (mod+n)%p;
        if(mod==0) return 0;
        
        unordered_map<int,int> map;
        map[0] = -1;
        
        int rem=0;
        int window=n,j=0;
        while(j<n){
            rem = (rem+nums[j])%p;
            int comp = (rem-mod+p)%p;
            
            if(map.find(comp) != map.end()){
                window = min(window , j-map[comp]);
            }
            
            map[rem] = j;
            j++;
        }
        
        return window==n ? -1 : window;
    }
};