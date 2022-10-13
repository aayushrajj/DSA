class Solution {
public:
    int count;
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        count =0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
    
    void mergeSort(vector<int> &nums, int s,int e){
        if(s==e) return;
        
        int mid = s + (e-s)/2;
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        
        count_valid(nums,s,mid,e);
        
        return;
    }
    
    void count_valid(vector<int> &nums,int s,int mid,int e){
        int l = s;
        int r = mid+1;
        
        while(l<=mid && r<=e){
            if(nums[l]/2.0 > nums[r])
                count += mid-l+1 , r++;
            else
                l++;
        }
        
        sort(nums.begin()+s,nums.begin()+e+1);
        return;
    }
};