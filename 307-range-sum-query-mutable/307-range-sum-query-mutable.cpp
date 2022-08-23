class SegmentTree{
   vector<int> seg;
public:
    SegmentTree(){
        
    }
    
    SegmentTree(vector<int>& nums){
        int n = nums.size();
        seg.resize(4*n);
        build_ST(nums,0,0,n-1); // pos , left, right
    }
    
    void build_ST(vector<int>& nums,int pos,int left,int right){
        if(left==right){
            seg[pos] = nums[left];
            return;
        }
        
        int mid = left + (right-left)/2;
        build_ST(nums,2*pos+1,left,mid);
        build_ST(nums,2*pos+2,mid+1,right);
        
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }
    
    void updateTree(int pos,int left,int right,int index,int val){
        if(index<left || index>right)
            return;
        
        if(left==right){
            if(left==index)
                seg[pos] = val;
            return;
        }
        
        int mid = left + (right-left)/2;
        updateTree(2*pos+1,left,mid,index,val);
        updateTree(2*pos+2,mid+1,right,index,val);
        
        seg[pos] = seg[2*pos+1] + seg[2*pos+2];
    }
    
    int findQuery(int qleft,int qright,int left,int right,int pos){
        if(qleft<=left && qright>=right)
            return seg[pos];
        
        if(qleft>right || qright<left)
            return 0;
        
        int mid = left + (right-left)/2;
        int leftVal = findQuery(qleft,qright,left,mid,2*pos+1);
        int rightVal = findQuery(qleft,qright,mid+1,right,2*pos+2);
        
        return leftVal+rightVal;
    }
};

class NumArray {
    SegmentTree st;
    int n;
public:
    NumArray(vector<int>& nums) {
        st = SegmentTree(nums);
        n = nums.size();
    }
    
    void update(int index, int val) {
        st.updateTree(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return st.findQuery(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */