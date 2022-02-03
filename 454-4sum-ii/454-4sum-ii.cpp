class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
        unordered_map<int,int> absum;
        for(auto &a : nums1){
            for(auto &b : nums2){
                absum[a+b]++;
            }
        }
        
        int count =0;
        for(auto &c : nums3){
            for(auto &d : nums4){
                auto it = absum.find(0-c-d);
                if(it != absum.end())
                    count += it->second;
            }
        }
        
        return count;
    }
};