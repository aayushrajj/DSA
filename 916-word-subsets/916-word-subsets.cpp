class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<char> sonCount(26,0);
        for(auto &baby : words2){
            vector<char> babyCount(26,0);
            for(auto ch : baby){
                babyCount[ch-97]++;
                sonCount[ch-97] = max(sonCount[ch-97],babyCount[ch-97]);
            }
        }
        for(int i=0;i<words1.size();i++){
            string dad = words1[i];
            bool flag = true;
            vector<char> dadCount(26,0);
            for(auto ch : dad){
                dadCount[ch-97]++;
            }
            for(int i=0;i<26;i++){
                if(dadCount[i]<sonCount[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(dad);
        }
        return res;
    }
};