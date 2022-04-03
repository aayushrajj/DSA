class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int res = start ^ goal;
        while(res){
            count += res&1;
            res = res>>1;
        }
        return count;
    }
};