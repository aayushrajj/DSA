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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // binary search on the left side of mountain
        int lo = 0;
        int hi = mountainArr.length() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal < mountainArr.get(mid + 1) && midVal < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        if (mountainArr.get(lo) == target)
            return lo;
        
        // binary search on the right side of mountain
        hi = mountainArr.length() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;
            int midVal = mountainArr.get(mid);
            if (midVal < mountainArr.get(mid - 1) && midVal < target)
                hi = mid - 1;
            else
                lo = mid;
        }
        if (mountainArr.get(hi) == target)
            return hi;
        else
            return -1;  
    }
};