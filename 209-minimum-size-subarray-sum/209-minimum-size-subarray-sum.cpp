class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = INT_MAX;
        vector<int> prefix(n+1,0);
        prefix[0] = 0;
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        int j=1;
        while(j<=n){
            int to_find = prefix[j-1]+target;
            auto bound = lower_bound(prefix.begin() , prefix.end() , to_find);
            if(bound != prefix.end()){
                minlen = min(minlen,static_cast<int>(bound - (prefix.begin() + j - 1)));
            }
            j++;
        }
        return minlen==INT_MAX ? 0 : minlen;
    }
};