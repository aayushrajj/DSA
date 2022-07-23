class NumberContainers {
public:
    unordered_map<int,set<int>> map;
    unordered_map<int,int> idxStore;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = idxStore.find(index);
        if(it != idxStore.end())
            map[it->second].erase(index);
        idxStore[index] = number;
        map[number].insert(index); 
    }
    
    int find(int number) {
        auto it = map.find(number);
        return it==map.end() || it->second.empty() ? -1 : *(it->second).begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */