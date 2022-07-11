class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>> view(rowIndex+1);
        
        for(int i=0;i<=rowIndex;i++){
            view[i].resize(i+1);
            view[i][0] = view[i][i] = 1;
            
            for(int j=1;j<i;j++){
                view[i][j] = view[i-1][j-1] + view[i-1][j];
            }
        }
        
        return view[rowIndex];
    }
};