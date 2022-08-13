class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=1;
        }
        vector<long long int>dp(n+1,0);
        dp[1]=1;
        long long int temp=0;
        int v;
        for(int i=2;i<=n;i++)
        {
            temp=INT_MAX;
            for(int j=0;j<arr.size();j++)
            {
                long long int count=mp[arr[j]];
                if(temp>(dp[count]*arr[j]))
                {
                    temp=dp[count]*arr[j];
                    v=arr[j];
                }
                else if(temp==(dp[count]*arr[j]))
                {
                    mp[arr[j]]++;
                }
            }
            mp[v]++;
            dp[i]=temp;
        }
        return dp[n];
    }
};