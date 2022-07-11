class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> view(numRows);
        
        view[0].push_back(1);
        if(numRows==1)
            return view;
        
        view[1].push_back(1);
        view[1].push_back(1);
        if(numRows==2)
            return view;
        
        for(int i=2;i<numRows;i++){
            view[i].resize(i+1);
            view[i][0] = 1;
            view[i][i] = 1;
            for(int j=1;j<i;j++){
                view[i][j] = view[i-1][j-1] + view[i-1][j];
            }
        }
        
        return view;
    }
};