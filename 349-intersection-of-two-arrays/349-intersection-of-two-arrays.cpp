class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        auto size1 = nums1.size();
        auto size2 = nums2.size();
        
        if(size1 == 0 || size2 == 0) return vector<int>();
        
        // assume sorted
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // we will use nums1 as a space for putting intersected elements
        // P is an index counter for it
        auto p = 0; 

        auto p1 = 0; // counter for iterating nums1
        auto p2 = 0; // counter for iterating nums2
        
        while(true) {
            auto a = nums1[p1];
            auto b = nums2[p2];

            if(a == b && (p == 0 || a != nums1[p-1])) {
                nums1[p] = a; // we are setting intersected elements to the beginning of nums1
                p++;
            }
            if(a < b) p1++;
            else p2++;
            if(p1 == size1 || p2 == size2) break;
        }
        
        nums1.erase(nums1.begin() + p, nums1.end()); // and we are erasing all other elements from nums1
        return nums1;
    }
};