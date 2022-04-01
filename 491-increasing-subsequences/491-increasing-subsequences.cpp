class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> seq;
        set<vector<int>> hash;
        backtrack(nums,seq,hash,0);
        return vector<vector<int>>(hash.begin(),hash.end());
    }
    
    void backtrack(vector<int> &nums,vector<int> seq,set<vector<int>> &hash,int i){
        if(i==nums.size()){
            if(seq.size()>1)
                hash.insert(seq);
            return;
        }
        if(seq.empty() || nums[i]>=seq.back()){
            seq.push_back(nums[i]);
            backtrack(nums,seq,hash,i+1);
            seq.pop_back();
        }
        backtrack(nums,seq,hash,i+1);
    }
};