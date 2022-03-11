class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size() , m = num2.size();
        string res(m+n,'0');
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int sum = (num1[i]-'0')*(num2[j]-'0') + (res[i+j+1]-'0');
                res[i+j+1] = sum%10 + '0';
                res[i+j] += sum/10;
            }
        }
        for(int i=0;i<m+n;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};