class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<n;i++){
            if(nums[i]&1)
                odd.push_back(nums[i]);
            else
                even.push_back(nums[i]);
        }
        vector<int> ans;
        int half = n/2;
        int j=0;
        while(j<half){
            ans.push_back(even[j]);
            ans.push_back(odd[j]);
            j++;
        }
        return ans;
    }
};