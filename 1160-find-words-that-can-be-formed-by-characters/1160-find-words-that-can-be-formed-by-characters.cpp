class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = words.size();
        int m = chars.length();
        int global=0;
        unordered_map<char,int> store;
        for(int i=0;i<m;i++){
            store[chars[i]]++;
        }
        for(int i=0;i<n;i++){
            string temp = words[i];
            unordered_map<char,int> map;
            for(int j=0;j<temp.length();j++){
                map[temp[j]]++;
            }
            int len =0;
            for(auto v : map){
                if(store.find(v.first)!=store.end() && store[v.first]>=map[v.first])
                    len += v.second;
            }
            if(len==temp.length())
                global += len;
        }
        return global;
    }
};