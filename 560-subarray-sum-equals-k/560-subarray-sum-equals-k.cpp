class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;
        int prefix =0,count=0;
        int i=0,j=0;
        while(j<n){
            prefix += nums[j];
            if(prefix==k)
                count++;
            if(map.find(prefix-k)!=map.end())
                count += map[prefix-k];
            map[prefix]++;
            j++;
        }
        return count;
    }
};