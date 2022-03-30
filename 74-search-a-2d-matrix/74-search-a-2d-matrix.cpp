class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(target==matrix[mid][0])
                return true;
            else if(target>matrix[mid][0])
                low = mid+1;
            else
                high = mid-1;
        }
        int row = high;
        if(row<0)
            return false;
        low = 0;
        high = matrix[row].size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(target==matrix[row][mid])
                return true;
            else if(target>matrix[row][mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};