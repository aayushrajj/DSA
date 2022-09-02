class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0,Xor = x^y;
        while(Xor){
            if(Xor & 1)
                count++;
            Xor >>= 1;
            
        }
        return count;
    }
};