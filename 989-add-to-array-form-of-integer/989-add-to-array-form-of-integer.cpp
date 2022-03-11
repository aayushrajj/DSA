class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size()-1;
        int carry = 0;
        while(i>=0 || carry || k){
            if(i>=0){
                int sum = num[i]+carry+k%10;
                num[i] = sum%10;
                carry = sum/10;
                k = k/10;
            }
            else{
                carry += k%10;
                num.insert(num.begin(),carry%10);
                k = k/10;
                carry = carry/10;
            }
            i--;
        }
        return num;
    }
};