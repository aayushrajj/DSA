class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxlen=1,count=1;
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                nums.erase(nums.begin()+i),i--;
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1)
                count++;
            else
                count = 1;
            if(count>maxlen)
                maxlen = count;
        }
        return maxlen;
    }
};