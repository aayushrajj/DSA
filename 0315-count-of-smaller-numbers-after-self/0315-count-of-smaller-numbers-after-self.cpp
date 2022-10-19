class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        vector<pair<int,int>> new_nums;
        vector<pair<int,int>> temp;
        
        for(int i=0;i<n;i++){
            new_nums.push_back({nums[i],i});
            temp.push_back({nums[i],i});
        }
        
        mergeSort(new_nums,temp,count,0,n-1);
        
        return count;
    }
    
    void mergeSort(vector<pair<int,int>> &nums,vector<pair<int,int>> &temp,vector<int> &count,int start ,int end){
        if(start>=end) return;
        
        int mid = start + (end-start)/2;
        
        mergeSort(nums,temp,count,start,mid);
        mergeSort(nums,temp,count,mid+1,end);
        
        int left = start, right = mid+1;
        int idx = start;
        int toRightLess = 0;
        while(left<=mid && right <= end){
            if(nums[left] < nums[right]){
                count[nums[left].second] += toRightLess;
                temp[idx++] = nums[left++];
            }
            else if(nums[left] > nums[right]){
                temp[idx++] = nums[right++];
                toRightLess++;
            }
            else{
                left++ , right++;
            }
        }
        
        while(left<=mid){
            count[nums[left].second] += toRightLess;
            temp[idx++] = nums[left++];
        }
        while(right<=end){
            temp[idx++] = nums[right++];
        }
        
        for(int i=start;i<=end;i++){
            nums[i] = temp[i];
        }  
    }
};