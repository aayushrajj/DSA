class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n,1);
        vector<int> count(n,1);
        
        int maxlen = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[j]+1 > lis[i]){
                        lis[i] = lis[j]+1;
                        count[i] = count[j];
                    }
                    else if(lis[j]+1 == lis[i]){
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen,lis[i]);
        }
        
        int maxcount = 0;
        for(int i=0;i<n;i++){
            if(lis[i]==maxlen){
                maxcount += count[i];
            }
        }
        
        return maxcount;
    }
};