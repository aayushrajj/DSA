class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = brackets.size();
        double tax=0;
        for(int i=0;i<n;i++){
            if(income>=brackets[i][0]){
                if(i==0){
                    double currTax = brackets[i][0] * (brackets[i][1]/100.0);
                    // number  * (float)(30/100.0)
                    tax += currTax;
                }
                else{
                    double currIncome = brackets[i][0] - brackets[i-1][0];
                    double currTax = currIncome * (brackets[i][1]/100.0);
                    tax += currTax;
                }
            }
            else{
                if(i==0){
                    double currTax = income * (brackets[i][1]/100.0);
                    tax += currTax;
                }
                else{
                    double currIncome = income - brackets[i-1][0];
                    double currTax = currIncome * (brackets[i][1]/100.0);
                    tax += currTax;
                }
                break;
            }
        }
        return tax;
    }
};