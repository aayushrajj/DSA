class Solution {
public:
/*
    This question is about longest increasing sequence from both sides
    let take example 
        ith index
        left[i] = x //length of increasing sequence from left side till ith index
        right[i] = y //length of increasing sequence form right side till ith index
        
        now x+y will be size of mountain if we suppose peak at ith index
        
        now how many indexes we have removed will be -> n - (x+y)
        and we have to minimize this.
        
    
*/
int minimumMountainRemovals(vector<int>& nums) {
    vector<int> left(nums.size(), 1), right(nums.size(), 1);
    
    vector<int> cpy; // this will store our LIS
    //LIS can be found in nlogn with binary search
    
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        auto it = lower_bound(begin(cpy), end(cpy), nums[i]); //chekcing if any element less than equal to ith element in our sequence with binary search 
        
        if(it != cpy.end()) *it = nums[i]; // if yes then we replace that element in our sequence.
        else cpy.push_back(nums[i]); //else we push it in our sequence.
        left[i] = cpy.size(); //and size of sequence till ith index from left side
    }
    
    cpy.clear();
    
    //same can be done from right side.
    
    for(int i=n-1; i>=0; i--){
        auto it = lower_bound(begin(cpy), end(cpy), nums[i]);
        if(it != cpy.end()) *it = nums[i];
        else cpy.push_back(nums[i]);
        right[i] = cpy.size();
    }
    
    
    //at last calculating ans
    
    int ans = n;
    for(int i=0; i<nums.size(); i++){
        if(left[i]-1 && right[i]-1){ //if sequence length is 1 from any side then this index can't be peak of mountain.
            int x = n - (left[i]+right[i]-1);
            ans = min(ans, x);
        }
    }
    
    return ans;
}
};