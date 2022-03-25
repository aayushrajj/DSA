class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> map;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum==goal)
                count++;
            if(map.find(sum-goal)!=map.end())
                count += map[sum-goal];
            map[sum]++;
        }
        return count;
    }
};