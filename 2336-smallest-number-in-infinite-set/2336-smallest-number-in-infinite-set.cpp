class SmallestInfiniteSet {
public:
    vector<int> nums = vector<int>(1001,1);
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int res=0;
        for(int i=1;i<1001;i++){
            if(nums[i]==1){
                res = i;
                nums[i] = 0;
                break;
            }          
        }
        return res;
    }
    
    void addBack(int num) {
        nums[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */