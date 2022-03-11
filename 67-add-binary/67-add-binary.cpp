class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i=a.length()-1 , j=b.length()-1;
        int sum=0,carry=0;
        while(i>=0 && j>=0){
            sum = a[i]-'0' + b[j]-'0';
            sum += carry;
            if(sum==0){
                carry=0;
                res.insert(0,"0"); 
            }
            else if(sum==1){
                carry = 0;
                res.insert(0,"1");
            }
            else if(sum==2){
                carry= 1;
                res.insert(0,"0");
            }
            else{
                carry = 1;
                res.insert(0,"1");
            }
            i--; j--;
        }
        while(i>=0){
            sum = carry + a[i]-'0';
            if(sum==0){
                carry=0;
                res.insert(0,"0"); 
            }
            else if(sum==1){
                carry = 0;
                res.insert(0,"1");
            }
            else if(sum==2){
                carry= 1;
                res.insert(0,"0");
            }
            else{
                carry = 1;
                res.insert(0,"0");
            }
            i--;
        }
        while(j>=0){
            sum = carry + b[j]-'0';
            if(sum==0){
                carry=0;
                res.insert(0,"0"); 
            }
            else if(sum==1){
                carry = 0;
                res.insert(0,"1");
            }
            else if(sum==2){
                carry= 1;
                res.insert(0,"0");
            }
            else{
                carry = 1;
                res.insert(0,"0");
            }
            j--;
        }
        if(carry>0){
            res.insert(0,"1");
        }
        return res;
    }
};