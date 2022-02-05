class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        int maxlen = 0 , sum = 0;
        for(int i=0;i<n;i++){
            sum += (nums[i]==1 ? 1 : -1);
            if(sum==0)
                maxlen = max(maxlen , i+1);
            else if(map.find(sum)!=map.end())
                maxlen = max(maxlen , i-map[sum]);
            else
                map[sum] = i;
        }
        return maxlen;
    }
};