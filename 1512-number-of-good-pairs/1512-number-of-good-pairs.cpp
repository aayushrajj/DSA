class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        int total =0;
        for(int a : nums){
            total += map[a];
            map[a]++;
        }
        return total;
    }
};