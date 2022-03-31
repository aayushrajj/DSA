class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permutate(nums,0,result);
        return result;
    }
    
    void permutate(vector<int> &nums,int i,vector<vector<int>> &result){
        if(i==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            // option to select either ith or jth , here we select here jth element
            swap(nums[i],nums[j]);
            permutate(nums,i+1,result);
            //reset and now here we select ith element
            swap(nums[i],nums[j]);
        }
    }
};