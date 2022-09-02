class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool alt = false;
        if(n&1)
            alt = true;
        n >>= 1;
        while(n){
            if(alt && n&1)
                return false;
            if(!alt && !(n&1))
                return false;
            
            alt = !alt;
            n >>= 1;
        }
        return true;
    }
};