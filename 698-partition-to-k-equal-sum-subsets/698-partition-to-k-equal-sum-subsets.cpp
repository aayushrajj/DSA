class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<k) return false;
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0) return false;
        int sum = total/k;
        sort(begin(nums),end(nums),greater<int>());
        vector<bool> visited(n);
        int currSum=0;
        return backtrack(nums,visited,currSum,sum,k,0);
    }
    
    bool backtrack(vector<int> &nums,vector<bool> &visited,int currSum,int sum,int k,int currIdx){
        if(k==1) return true;
        if(currIdx==nums.size())
            return false;
        if(currSum>sum)
            return false;
        if(currSum==sum)
            return backtrack(nums,visited,0,sum,k-1,0);
        for(int i=currIdx;i<nums.size();i++){
            if(visited[i] || currSum+nums[i]>sum)
                continue;
            visited[i] = true;
            if(backtrack(nums,visited,currSum+nums[i],sum,k,i+1))
                return true;
            visited[i] = false;
        }
        return false;
    }
};