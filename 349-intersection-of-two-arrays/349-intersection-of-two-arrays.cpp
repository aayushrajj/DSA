class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> map1;
        for(int v : nums1)
            map1[v]++;
        for(int i=0;i<nums2.size();i++){
            if(map1[nums2[i]]>0){
                ans.push_back(nums2[i]);
                map1[nums2[i]] = 0;
            }
        }
        return ans;
    }
};