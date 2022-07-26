class Solution {
public:
    int longestMountain(vector<int>& A) {
        int maxMnt = 0;
    
        int i = 1;
        while (i < A.size()) {
            while(i < A.size() && A[i-1] == A[i])
                ++i;
            
            int up = 0;
            while(i < A.size() && A[i-1] < A[i]) {
                ++up;
                ++i;
            }
            
            int down = 0;
            while(i < A.size() && A[i-1] > A[i]) {
                ++down;
                ++i;
            }
            
            if (up > 0 && down > 0)  
                maxMnt = max(maxMnt, up+down+1);
            
        }
        
        return maxMnt;
    }
};