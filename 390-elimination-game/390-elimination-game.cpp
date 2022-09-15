class Solution {
public:
    int lastRemaining(int n) {
        int head =1;
        int remain =n;
        bool left = true;
        int steps=1;
        
        while(remain>1){
            if(left || remain%2==1){
                head += steps;
            }
            
            remain /= 2;
            steps *= 2;
            left = !left;
        }
        
        return head;
    }
};