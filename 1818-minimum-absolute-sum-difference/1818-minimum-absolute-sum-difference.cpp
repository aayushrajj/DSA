class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long minDiff = 0 , gain = 0;
        set<int> store(begin(nums1) , end(nums1));
        
        for(int i=0; i<nums2.size(); i++){
            long diff = abs(nums1[i] - nums2[i]);
            minDiff += diff;
            
            if(gain < diff){
                auto it = store.lower_bound(nums2[i]);
                if(it != store.begin())
                    gain = max(gain , diff - abs(*prev(it) - nums2[i]) );
                if(it != store.end())
                    gain = max(gain , diff - abs(*it - nums2[i]));
            }
        }
        
        return ( minDiff - gain ) % 1000000007;
    }
};