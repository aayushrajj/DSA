class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        unordered_map<int,int> freq;
        set<int> visited;
        for(int i=0;i<arr1.size();i++){
            freq[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            int size = freq[arr2[i]];
            res.insert(res.end(),size,arr2[i]);
            visited.insert(arr2[i]);
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++){
            if(visited.find(arr1[i])==visited.end())
                res.push_back(arr1[i]);
        }
        return res;
    }
};