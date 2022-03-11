class Solution {
public:
    string convertToBase7(int num) {
        bool flag = false;
        if(num==0)
            return "0";
        else if(num<0){
            num = abs(num);
            flag = true;
        }
        string ans = "";
        while(num){
            int rem = num%7;
            ans += to_string(rem);
            num = num/7;
        }
        if(flag)
            ans += "-";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};