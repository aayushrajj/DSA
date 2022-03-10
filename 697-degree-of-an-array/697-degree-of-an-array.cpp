class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> count , first_seen;
        int degree =0;
        int min_len = 0;
        for(int i=0;i<nums.size();i++){
            if(first_seen.count(nums[i])==0)
                first_seen[nums[i]] = i;
            count[nums[i]]++;
            if(degree<count[nums[i]]){
                degree = count[nums[i]];
                min_len = i-first_seen[nums[i]]+1;
            }
            else if(degree==count[nums[i]])
                min_len = min(min_len,i-first_seen[nums[i]]+1);
        }
        return min_len;
    }
};