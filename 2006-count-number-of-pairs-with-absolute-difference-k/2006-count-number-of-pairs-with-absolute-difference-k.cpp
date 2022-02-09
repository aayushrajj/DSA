class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;
        int count =0;
        for(int num : nums){
            count += map[num+k] + map[num-k];
            map[num]++;
        }
        return count;
    }
};