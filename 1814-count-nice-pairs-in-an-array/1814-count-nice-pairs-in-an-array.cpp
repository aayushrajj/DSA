class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> map;
        int count=0 , mod=1e9+7;
        for(auto num : nums){
            count = (count + map[num - rev(num)]++ )%mod; ;
        }
        
        return count;
    }
    
    int rev(int n){
        int ans=0;
        while(n>0){
            int rem = n%10;
            n = n/10;
            ans = ans*10 + rem;
        }
        return ans;
    }
};