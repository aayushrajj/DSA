class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        while(low<high){
            int mid = low + (high-low)/2;
            if(check(m,n,mid,k))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
    
    bool check(int m,int n,int mid,int k){
        int count=0;
        for(int i=1;i<=m;i++){
            count += min(mid/i,n);
        }
        
        return count>=k;
    }
};