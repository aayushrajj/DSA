class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxarea = 0;
        vector<int> nextSmallerRight(n);
        vector<int> nextSmallerLeft(n);
        stack<int> st1;
        stack<int> st2;
        for(int i=n-1;i>=0;i--){
            while(!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();
            if(st1.empty())
                nextSmallerRight[i] = n;
            else
                nextSmallerRight[i] = st1.top();
            st1.push(i);
        }
        for(int i=0;i<n;i++){
            while(!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();
            if(st2.empty())
                nextSmallerLeft[i] = -1;
            else
                nextSmallerLeft[i] = st2.top();
            st2.push(i);
        }
        
        for(int i=0;i<n;i++){
            int width = nextSmallerRight[i]-nextSmallerLeft[i]-1;
            int area = width*heights[i];
            maxarea = max(area,maxarea);
        }
        return maxarea;
    }
};