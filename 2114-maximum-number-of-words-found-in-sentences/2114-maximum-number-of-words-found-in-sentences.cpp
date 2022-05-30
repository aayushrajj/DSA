class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(auto i : sentences){
            maxi = max(maxi , check(i));
        }
        return maxi;
    }
    
    int check(string s){
        int total = 0;
        s += ' ';
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' ')
                total++;
        }
        return total;
    }
};