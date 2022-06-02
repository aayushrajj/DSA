class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<int> map(101,0);
        for( auto log : logs){
            for(int i=log[0];i<log[1];i++){
                map[i-1950]++;
            }
        }
        int maxpol = 0,year=0;
        for(int i=0;i<=100;i++){
            if(map[i] > maxpol){
                maxpol = map[i];
                year = i;
            }
        }
        
        return year+1950;
    }
};