class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int curr = 1;
        for(int i=0;i<n;i++){
            res[i] = curr;
            if(curr*10 <= n)
                curr = curr*10;
            else{
                if(curr>=n)
                    curr = curr/10;
                curr = curr+1;
                while(curr%10 == 0)
                    curr = curr/10;
                
            }
        }
        return res;
    }
};