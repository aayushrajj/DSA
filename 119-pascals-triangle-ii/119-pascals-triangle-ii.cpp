class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>> view(rowIndex+1);
        
        view[0].push_back(1);
        if(rowIndex==0)
            return view[0];
        
        view[1].push_back(1);
        view[1].push_back(1);
        if(rowIndex==1)
            return view[1];
        
        for(int i=2;i<=rowIndex;i++){
            view[i].resize(i+1);
            view[i][0] = 1;
            view[i][i] = 1;
            for(int j=1;j<i;j++){
                view[i][j] = view[i-1][j-1] + view[i-1][j];
            }
        }
        
        return view[rowIndex];
    }
};