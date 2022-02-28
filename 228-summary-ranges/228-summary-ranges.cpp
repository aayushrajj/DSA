class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        vector<string> result;
        int start = nums[0];
        for(int i=0;i<n;i++){
            if(i==n-1 || nums[i]+1!=nums[i+1]){
                if(nums[i]!=start)
                    result.push_back(to_string(start)+"->"+to_string(nums[i]));
                else
                    result.push_back(to_string(start));
                
                if(i!=n-1)
                    start = nums[i+1];
            }
        }
        return result;
    }
};