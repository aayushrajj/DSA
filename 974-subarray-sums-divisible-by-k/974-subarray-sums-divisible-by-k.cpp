class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;
        int prefix=0,count=0;
        map[0] = 1;
        int j=0;
        while(j<n){
            prefix += nums[j];
            
            int rem = prefix%k;
            if(rem<0) rem+= k;
            
            if(map.find(rem)!=map.end())
                count += map[rem];
            
            map[rem]++;
            j++;
        }
        
        return count;
    }
};