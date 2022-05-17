class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int left = 1, right = n-2;
        int leftMax = height[0];
        int rightMax = height[n-1];
        while(left<=right){
            if(leftMax < rightMax){
                if(height[left] > leftMax)
                    leftMax = height[left];
                else
                    total += leftMax - height[left];
                left++;
            }
            else{
                if(height[right] > rightMax)
                    rightMax = height[right];
                else
                    total += rightMax - height[right];
                right--;
            }
        }
        return total;
    }
};