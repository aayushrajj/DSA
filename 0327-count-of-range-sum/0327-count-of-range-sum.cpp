class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long n = nums.size();
        if(n==0) return 0;
        
        vector<long> sums(n+1,0);
        for(long i=0;i<n;i++){
            sums[i+1] = sums[i] + nums[i];
        }
        
        return mergeSort(sums,lower,upper,0,n+1);
    }
    
    int mergeSort(vector<long> &sums,long lower,long upper,long start,long end){
        if(end-start<=1)
            return 0;
        
        long mid = start + (end-start)/2;
        
        long count = mergeSort(sums,lower,upper,start,mid) +
                    mergeSort(sums,lower,upper,mid,end);
        
        long m = mid , n = mid;
        for(long i=start;i<mid;i++){
            while(m < end && sums[m] - sums[i] < lower) m++;
            while(n < end && sums[n] - sums[i] <= upper) n++;
            count += n-m;
        }
        
        inplace_merge(sums.begin()+start, sums.begin()+mid, sums.begin()+end);
        
        return count;
    }
};