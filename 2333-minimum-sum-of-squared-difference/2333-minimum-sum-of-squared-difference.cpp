class Solution {
public:
    typedef long long int;
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(1e5+1,0);
        
        for(int i=0;i<nums1.size();i++){
            diff[abs(nums1[i] - nums2[i])]++;
        }
        
        int k = k1+k2;
        int curr =0;
        
        for(int i =1e5; i>=0; i--){
            curr = diff[i];
            if(curr <= k){
                if(i<=1)
                    return 0;
                diff[i-1] += diff[i];
                diff[i] = 0;
                k -= curr;
            }
            else{
                if(i==0)
                    return 0;
                diff[i] -= k;
                diff[i-1] += k;
                break;
            }
        }
        
        long long res =0;
        
        for(int i=1;i<=1e5;i++){
            res += (long long)diff[i] * ((long long)i*i);
        }
        
        return res;
    }
};