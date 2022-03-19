class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> score(n+1,0);
        vector<int> prefixZero(n,0);
        vector<int> suffixOne(n,0);
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[i]==0)
                    prefixZero[i] = 1;
            }
            else if(nums[i]==0)
                prefixZero[i] = prefixZero[i-1] + 1;
            else
                prefixZero[i] = prefixZero[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                if(nums[i]==1)
                    suffixOne[i] = 1;
            }
            else if(nums[i]==1)
                suffixOne[i] = suffixOne[i+1] + 1;
            else
                suffixOne[i] = suffixOne[i+1];
        }
        for(int i=0;i<=n;i++){
            if(i==0)
                score[i] = suffixOne[i];
            else if(i==n)
                score[i] = prefixZero[i-1];
            else
                score[i] = prefixZero[i-1] + suffixOne[i];
        }
        int prev = INT_MIN;
        for(int i=0;i<=n;i++){
            if(score[i]>prev){
                res.clear();
                res.push_back(i);
                prev = score[i];
            }
            else if(score[i]==prev)
                res.push_back(i);
        }
        return res;
    }
};