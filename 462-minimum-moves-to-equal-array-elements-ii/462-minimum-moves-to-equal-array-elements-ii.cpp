class Solution {
public:
    #define ll long long
    int minMoves2(vector<int>& nums) {
        ll n = nums.size();
        sort(nums.begin(),nums.end());
        
        ll mid = n/2;
        ll res = 0;
        for(ll i=0;i<n;i++){
            res += abs( nums[i] - nums[mid] );
        }
        
        return res;
    }
};



 