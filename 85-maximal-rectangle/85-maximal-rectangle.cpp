class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int finalarea = 0;
        
        vector<vector<int>> dp(n,vector<int> (m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = matrix[i][j] - '0';
            }
        }
        
        for(int i=0;i<n;i++){
            vector<int> temp(m,1);
            for(int j=0;j<m;j++){
                if(i==0)
                    temp[j] = dp[i][j];
                else if(dp[i][j] == 0)
                    temp[j] = 0;
                else{
                    int prev = dp[i-1][j];
                    int curr = prev + dp[i][j];
                    dp[i][j] = curr;
                    temp[j] = curr;
                }
            }
            int rowarea = maximumAreaHistogram(temp);
            finalarea = max(rowarea,finalarea);
        }
        
        return finalarea;
    }
    
    int maximumAreaHistogram(vector<int> &heights){
        int n = heights.size();
        int maxarea = 0;
        vector<int> nextSmallerRight(n);
        vector<int> nextSmallerLeft(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                nextSmallerRight[i] = n;
            else
                nextSmallerRight[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
               nextSmallerLeft[i] = -1;
            else
                nextSmallerLeft[i] = st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            int width = nextSmallerRight[i]-nextSmallerLeft[i]-1;
            int area = heights[i]*width;
            maxarea = max(area,maxarea);
        }
        return maxarea;
    }
};