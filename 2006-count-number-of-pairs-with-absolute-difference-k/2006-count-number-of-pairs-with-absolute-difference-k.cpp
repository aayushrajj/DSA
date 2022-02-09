class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int num : nums){
            map[num]++;
        }
        int count=0;
        for(auto p : map){
            int pair = p.first+k;
            if(map.find(pair)!=map.end()){
                count += p.second * map.find(pair)->second;
            }
        }
        return count;
    }
};