class StockSpanner {
public:
    stack<pair<int,int>> store;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int idx = 1;
        while(!store.empty() && store.top().first <= price){
            idx += store.top().second;
            store.pop();
        }
        
        store.push({price,idx});
        return idx;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */