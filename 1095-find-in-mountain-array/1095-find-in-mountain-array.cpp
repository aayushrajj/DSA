/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int n;
    int findInMountainArray(int target, MountainArray &mountainArr) {
        n = mountainArr.length();
        int low =0 , high = n-1;
        int peak = findPeak(mountainArr,low,high);
        
        low = 0 , high = peak-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int midVal = mountainArr.get(mid);
            if(midVal==target)
                return mid;
            else if(midVal>target)
                high = mid-1;
            else
                low = mid+1;
        }
        
        low = peak , high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int midVal = mountainArr.get(mid);
            if(midVal==target)
                return mid;
            else if(midVal>target)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
    }
    
    int findPeak(MountainArray &mountainArr,int &low,int &high){
        while(low<=high){
            int mid = low + (high-low)/2;
            int midVal = mountainArr.get(mid);
            if(mid>0 && mid<n-1){
                if(midVal > mountainArr.get(mid+1) &&
                   midVal > mountainArr.get(mid-1)){
                    return mid;
                }
                else if(mountainArr.get(mid-1) > midVal)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(mid==0){
                if(midVal > mountainArr.get(mid+1))
                    return mid;
                else
                    return mid+1;
            }
            else if(mid==n-1){
                if(midVal > mountainArr.get(mid-1))
                    return mid;
                else
                    return mid-1;
            }
        }
        
        return -1;
    }
};