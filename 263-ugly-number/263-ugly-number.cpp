class Solution {
public:
    bool isUgly(int n) {
        
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                while(n%i==0){
                    n = n/i;
                    if(i==2 || i==3 || i==5)
                        continue;
                    else
                        return false;
                }
            }
        }
        if(n!=1){
            if(n==2 || n==3 || n==5)
                return true;
            else
                return false;
        }
        return true;
    }
};