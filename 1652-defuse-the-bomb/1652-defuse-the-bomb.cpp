class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if(k==0)
            return res;
        else if(k>0){
            for(int i=0;i<n;i++){
                for(int j=1;j<=k;j++){
                    res[i] += code[(i+j)%n];
                }
            }
        }
        else if(k<0){
            for(int i=0;i<n;i++){
                for(int j=1;j<=k*-1;j++){
                    res[i] += code[(i-j+n)%n];
                }
            }
        }
        return res;     
    }
};