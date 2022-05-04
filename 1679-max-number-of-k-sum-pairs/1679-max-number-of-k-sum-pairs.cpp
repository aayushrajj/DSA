class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(map[k-nums[i]] > 0){
                count++;
                map[k-nums[i]]--;
            }
            else
                map[nums[i]]++;
        }
        return count;
    }
};