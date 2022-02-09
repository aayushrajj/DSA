class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int start = nums[0];
        int end = nums[n-1];
        map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        int total=0;
        for(auto p : map){
            if(k==0 && p.second>1)
                total++;
            else if(k!=0 && map.find(p.first+k)!=map.end())
                total++;
        }
        return total;
    }
};