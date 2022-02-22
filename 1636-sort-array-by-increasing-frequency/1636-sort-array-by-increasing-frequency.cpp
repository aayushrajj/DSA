// bool mysort(pair<int,int> &a , pair<int,int> &b){
//     return a.second==b.second ? a.first>b.first : a.second<b.second;
// }
bool mysort(vector<int> &a , vector<int> &b){
    return a[1]==b[1] ? a[0]>b[0] : a[1]<b[1];
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        for(int v : nums){
            map[v]++;
        }
        vector<vector<int>> store;
        for(auto v : map){
            store.push_back({v.first,v.second});
        }
        sort(store.begin(),store.end(),mysort);
        vector<int> res;
        for(int i=0;i<store.size();i++){
            for(int j=0;j<store[i][1];j++){
                res.push_back(store[i][0]);
            }
        }
        return res;
    }
};