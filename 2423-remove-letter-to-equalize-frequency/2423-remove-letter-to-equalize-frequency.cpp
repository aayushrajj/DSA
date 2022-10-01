class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.length();
        for(int i=0;i<n;i++){
            string copy = word;
            copy.erase(copy.begin()+i);
            bool curr = check(copy);
            if(curr==true)
                return true;
        }
        
        return false;
    }
    
    bool check(string substring){
        vector<int> arr(26);
        for(auto i : substring){
            arr[i-97]++;
        }
        set<int> map;
        for(int i=0;i<26;i++){
            if(arr[i]!=0)
                map.insert(arr[i]);
        }
        return map.size()==1;
    }
};