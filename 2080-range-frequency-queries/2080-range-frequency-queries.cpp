class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> map;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
            map[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        auto last = upper_bound(map[value].begin(),map[value].end(),right);
        auto front = lower_bound(map[value].begin(),map[value].end(),left);
        return last - front;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */