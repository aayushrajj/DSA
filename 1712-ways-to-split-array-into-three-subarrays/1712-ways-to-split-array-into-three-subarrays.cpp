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
        
        // int count=0;
//         for(int i=0;i<n-2;++i){
//             if(sum[i]> (sum[n-1]-sum[i])/2)
//                 continue;
//             ll leftSum = sum[i];
//             ll midSum=0,rightSum=0;
            
//             //for mid subarray
//             int low = i+1,high=n-2;
//             while(low<high){
//                 int mid = low + (high-low)/2;
//                 midSum = sum[mid]-sum[i];
//                 rightSum = sum[n-1]-sum[mid];
//                 if(midSum<leftSum)
//                     low = mid+1;
//                 else
//                     high = mid;
//             }
//             int left = low;
            
//             // for right subarray
//             high = n-2;
//             while(low<high){
//                 int mid = low + (high-low)/2;
//                 midSum = sum[mid]-sum[i];
//                 rightSum = sum[n-1]-sum[mid];
//                 if(midSum>rightSum)
//                     high= mid-1;
//                 else
//                     low = mid;
//             }
//             int right = low;
            
//             if(sum[right]-sum[i] <= sum[n-1]-sum[right])
//                 count = (count + (right-left+1)%mod) % mod;
                
//         }
        
//         return count;    
        
        int res=0;
        for (int j = 0; j < n - 2; ++j) {
            if (presum[j] > (presum[n - 1] - presum[j]) / 2)
                continue;
            int leftsum = presum[j], midsum = 0, rightsum = 0;
            int lo = j + 1, hi = n - 2;
            while (lo < hi) {
                int mid = lo + ((hi - lo)>>1);
                midsum = presum[mid] - presum[j];
                rightsum = presum[n - 1] - presum[mid];
                if (midsum < leftsum)
                    lo = mid + 1;
                else hi = mid;
            }
            int left = lo;
            hi = n - 2;
            while (lo < hi) {
                int mid = hi - ((hi - lo)>>1);
                midsum = presum[mid] - presum[j];
                rightsum = presum[n - 1] - presum[mid];
                if (midsum > rightsum)
                    hi = mid - 1;
                else lo = mid;
            }
            int right = lo;
            if (presum[right] - presum[j] <= presum[n - 1] - presum[right])
                res = (res + (right - left + 1) % mod) % mod;
        }
        return res;
    }
};