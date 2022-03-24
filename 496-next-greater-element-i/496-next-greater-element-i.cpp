class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res(n,-1);
        int i=0;
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<m;j++){
                if(nums2[j]==nums1[i])
                    flag = true;
                if(flag==true && nums2[j]>nums1[i]){
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};