class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int half = n/2;
        unordered_map<int,int> map;
        for(auto num : arr)
            map[num]++;
        
        priority_queue<int> store;
        for(auto v : map)
            store.push(v.second);
        
        int count=0,size=0;
        while(size<half){
            size += store.top();
            store.pop();
            count++;
        }
        
        return count;
    }
};