class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = ages.size();
        vector<vector<int>> player;
        for(int i=0;i<n;i++){
            player.push_back({ages[i],scores[i]});
        }
        sort(player.begin(),player.end());
        int maxscore=0;
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            int score = player[i][1];
            dp[i] = score;
            for(int j=0;j<i;j++){
                if(player[j][1]<=score){
                    dp[i] = max(dp[i],dp[j]+score);
                }
            }
            maxscore = max(maxscore,dp[i]);
        }
        return maxscore;
    }
};