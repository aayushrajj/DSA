class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int one = accumulate(begin(nums),end(nums),0);
        int zero = 0;
        int maxscore = INT_MIN;
        for(int i=0;i<=n;i++){
            if(zero + one > maxscore){
                maxscore = zero + one;
                res.clear();
                res.push_back(i);
            }
            else if(zero + one == maxscore)
                res.push_back(i);
            if(i<n){
                if(nums[i]==1) one--;
                if(nums[i]==0) zero++;
            }
        }
        return res;
    }
};