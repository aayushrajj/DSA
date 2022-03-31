class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permutate(nums,0,result);
        return result;
    }
    
    void permutate(vector<int> &nums,int i,vector<vector<int>> &result){
        if(i==nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int> visited;
        for(int j=i;j<nums.size();j++){
            if(visited.find(nums[j])!=visited.end())
                continue;
            visited.insert(nums[j]);
            swap(nums[j],nums[i]);
            permutate(nums,i+1,result);
            swap(nums[j],nums[i]);
        }
    }
};