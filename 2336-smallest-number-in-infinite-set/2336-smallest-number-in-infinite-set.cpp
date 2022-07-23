class SmallestInfiniteSet {
public:
    int curr;
    set<int> map;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(map.size()){
            int res = *map.begin();
            map.erase(res);
            return res;
        }
        else{
            curr += 1;
            return curr-1;
        }
    }
    
    void addBack(int num) {
        if(curr>num)
            map.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */