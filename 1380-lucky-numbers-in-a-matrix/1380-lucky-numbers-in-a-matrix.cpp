class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int colidx = -1;
            for(int j=0;j<m;j++){
                if(matrix[i][j]<mini){
                    mini = matrix[i][j];
                    colidx = j;
                }
            }
            int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                if(matrix[i][colidx]>maxi){
                    maxi = matrix[i][colidx];
                }
            }
            if(maxi==mini)
                ans.push_back(maxi);
        }
        return ans;
    }
};