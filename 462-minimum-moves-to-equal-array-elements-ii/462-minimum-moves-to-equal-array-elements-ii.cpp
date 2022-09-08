class Solution {
public:
    #define ll long long
    int minMoves2(vector<int>& nums) {
        ll n = nums.size(), steps = 0;
        nth_element(nums.begin(), nums.begin()+(n/2), nums.end()); 
        ll median = nums[n/2];
        for(ll i=0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};


 