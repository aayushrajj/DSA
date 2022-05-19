class LRUCache {
public:
    list<pair<int,int>> l;
    unordered_map< int , list<pair<int,int>>::iterator> map;
    int n;
    LRUCache(int capacity) {
       this->n = capacity; 
    }
    
    int get(int key) {
        if(map.find(key)==map.end())
            return -1;
        // It exists,so make it most recently used key, updated its address in map also
        l.splice(l.begin() , l , map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            l.splice(l.begin() , l , map[key]);
            map[key]->second = value;
            return;
        }
        // else check size
        if(map.size()==n){
            auto lrukey = l.back().first;
            l.pop_back();
            map.erase(lrukey);
        }
        
        // Now insert its new entry
        l.push_front({key,value});
        map[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */