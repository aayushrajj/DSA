class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int area = 0;
        vector<int> height(n,0);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            
            vector<int> ordered_height = height;
            sort(ordered_height.begin(),ordered_height.end());
            
            for(int j=0;j<n;j++){
                area = max(area , ordered_height[j]*(n-j));
            }
            
        }
        
        return area;
    }
};
