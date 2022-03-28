class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> common(26);
        vector<int> temp(26);
        vector<string> res;
        for(auto v : words[0])
            common[v-'a']++;
        for(int i=1;i<words.size();i++){
            for(auto v : words[i])
                temp[v-'a']++;
            for(int j=0;j<common.size();j++){
                common[j] = min(common[j],temp[j]);
                temp[j] = 0;
            }
        }
        for(int i=0;i<common.size();i++){
            while(common[i]--){
                string c = string(1,i+'a');
                res.push_back(c);
            }
        }
        return res;
    }
};