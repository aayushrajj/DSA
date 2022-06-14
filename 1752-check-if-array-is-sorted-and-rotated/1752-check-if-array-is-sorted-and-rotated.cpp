class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            bool flag = true;
            for(int j=0;j<n;j++){
                if(j<n-1 && nums[(j+i)%n] > nums[(j+1+i)%n]){
                    flag = false;
                    break;
                }
            }
            if(flag==true)
                return true;
            i++;
        }
        return false;
    }
};