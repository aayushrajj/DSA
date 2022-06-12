class Solution {
public:
    #define ll long long
    int minMoves2(vector<int>& nums) {
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        
        // ll total = accumulate(nums.begin(),nums.end(),0L);
        
        ll res = LONG_MAX;
        vector<ll> prefixSum(n);
        prefixSum[0] = nums[0];
        for(ll i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        for(ll i=0;i<n;i++){
            ll extra = 0;
            if(i==0){
                extra = prefixSum[n-1]-prefixSum[i] - nums[i]*(n-i-1) ;
            }
            else{
                extra = ( ( nums[i]*i ) - prefixSum[i-1] ) +
                ( ( prefixSum[n-1]-prefixSum[i] ) - nums[i]*(n-i-1) );
            }
            
            res = min(res , extra);
        }
        
        return res;
    }
};



        // for(ll i=0;i<n;i++){
        //     ll extra = abs( ( total - nums[i] ) - ( n-1 * nums[i] ) );
        //     res = min(res,extra);
        // }
        // return res;