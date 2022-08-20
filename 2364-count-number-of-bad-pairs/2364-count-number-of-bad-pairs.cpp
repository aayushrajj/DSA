typedef long long ll;
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> map;
        ll count=0;
        
        for(int i=0;i<nums.size();i++){
            count += i - map[i-nums[i]]++;
        }
        
        return count;
    }
};