class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(c || a || b){
            if(c&1){
                if((a&1)==0 && (b&1)==0)
                    count++;
            }
            else{
                if(a&1)
                    count++;
                if(b&1)
                    count++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return count;
    }
};