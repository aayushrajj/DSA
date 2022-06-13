class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums.push_back(grid[i][j]);
            }
        }
        
        sort(nums.begin(),nums.end());
        int target = nums[(m*n)/2];
        int count=0;
        for(int i=m*n-1;i>=0;i--){
            if(abs(nums[i]-target)%x!=0)
                return -1;
            else
                count += abs(nums[i]-target)/x;
        }
        
        return count;
    }
};