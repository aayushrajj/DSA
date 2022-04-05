class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int area=0;
        while(left<right){
            int width = right-left;
            int length = min(height[left],height[right]);
            area = max(area,(width*length));
            if(height[left]<height[right])
                left++;
            else if(height[right]<height[left])
                right--;
            else
                left++ , right--;
        }
        return area;
    }
};