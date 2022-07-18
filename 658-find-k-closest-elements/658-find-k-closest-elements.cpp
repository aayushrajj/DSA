class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left=0,right=n-k;
        while(left<right){
            int mid = left + (right-left)/2;
            if( x-arr[mid] > arr[mid+k]-x )
                left =  mid+1;
            else
                right = mid;
        }
        
        vector<int> result( arr.begin()+left , arr.begin()+left+k );
        return result;
    }
};