class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n){
            int rmsb = n & -n;
            n -= rmsb;
            count++;
        }
        return count;
    }
};