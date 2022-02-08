class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        while(num>=10){
            int total = 0;
            while(num!=0){
                int r = num%10;
                total += r;
                num = num/10;
            }
            if(total<10)
                return total;
            else
                num = total;
        }
        return 0;
    }
};