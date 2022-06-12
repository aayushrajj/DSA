class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int score =0 , maxscore =0;
        unordered_map<int,int> map;
        int i=0,j=0;
        while(j<n){
            map[nums[j]]++;
            while( map[nums[j]] > 1){
                map[nums[i]]--;
                score -= nums[i];
                i++;
            }
            score += nums[j];
            maxscore = max(maxscore , score);
            j++;
        }
        return maxscore;
    }
};