class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int globalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if(x > globalSum) return -1;
        
        int sum = globalSum - x;
        
        int i=0,j=0,window=0,len=-1;
        
        while(j<n){
            window += nums[j];
            while(window > sum){
                window -= nums[i];
                i++;
            }    
            if(window==sum)
                len = max(len , j-i+1);
            j++;
        }
        return len==-1 ? len : n-len;
    }
};