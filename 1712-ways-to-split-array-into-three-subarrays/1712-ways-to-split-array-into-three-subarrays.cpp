typedef long long ll;
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<ll> presum(n);
        presum[0] = nums[0];
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1] + nums[i];
        }
        
        int count=0;
        for(int i=0;i<n-2;++i){
            if(presum[i]> (presum[n-1]-presum[i])/2)
                continue;
            ll leftSum = presum[i];
            ll midSum=0,rightSum=0;
            
            //for mid subarray
            int low = i+1,high=n-2;
            while(low<high){
                int mid = low + (high-low)/2;
                midSum = presum[mid]-presum[i];
                rightSum = presum[n-1]-presum[mid];
                if(midSum<leftSum)
                    low = mid+1;
                else
                    high = mid;
            }
            int left = low;
            
            // for right subarray
            high = n-2;
            while(low<high){
                int mid = high - (high-low)/2;
                midSum = presum[mid]-presum[i];
                rightSum = presum[n-1]-presum[mid];
                if(midSum>rightSum)
                    high= mid-1;
                else
                    low = mid;
            }
            int right = low;
            
            if(presum[right]-presum[i] <= presum[n-1]-presum[right])
                count = (count + (right-left+1)%mod) % mod;
                
        }
        
        return count;
    }
};