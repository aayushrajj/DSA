class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> count(k,0);
        int sum=0;
        for(auto &n : nums){
            sum += (n%k +k)%k;
            count[sum%k]++;
        }
        
        int res = count[0];
        for(auto &c : count){
            res += (c*(c-1))/2;
        }
        return res;
    }
};