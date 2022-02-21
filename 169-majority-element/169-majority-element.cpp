class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int v : nums){
            map[v]++;
            if(map[v]>n/2)
                return v;
        }
        return 0;
    }
};