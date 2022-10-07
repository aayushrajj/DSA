class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> res;
        
        sort(nums.begin(),nums.end());
        
        // vector<int> prefixSum(n);
        // prefixSum[0] = nums[0];
        // for(int i=1;i<n;i++){
        //     prefixSum[i] = prefixSum[i-1] + nums[i];
        // }
        
        for(int j=0;j<m;j++){
            int currQ = queries[j];
            int currMaxlen = 0 , currSum = 0;
            int left=0;
            for(int i=0;i<n;i++){
                currSum += nums[i];
                while(left <= i && currSum > currQ){
                    currSum -= nums[left];
                    left++;
                }       
                currMaxlen = max(currMaxlen , i-left+1);
            }
            res.push_back(currMaxlen);
        }
        
        return res;
    }
};