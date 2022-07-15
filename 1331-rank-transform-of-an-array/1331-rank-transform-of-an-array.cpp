class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy = arr;
        sort(copy.begin(),copy.end());
        
        vector<int> rank(n);
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(i==0)
                rank[i] = 1 , map[copy[i]] = rank[i];
            else if(i>0 && copy[i]==copy[i-1])
                rank[i] = rank[i-1] , map[copy[i]] = rank[i];
            else
                rank[i] = rank[i-1]+1 , map[copy[i]] = rank[i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = map[arr[i]];
        }
        
        return res;
    }
};