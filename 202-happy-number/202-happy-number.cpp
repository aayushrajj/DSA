class Solution {
public:
    bool isHappy(int n) {
        int slow = next(n);
        int fast = next(next(n));
        while(slow!=fast){
            slow = next(slow);
            fast = next(next(fast));
        }
        return slow==1;
    }
    
    int next(int n){
        int res=0;
        while(n){
            int index = n%10;
            res += index*index;
            n = n/10;
        }
        return res;
    }
};