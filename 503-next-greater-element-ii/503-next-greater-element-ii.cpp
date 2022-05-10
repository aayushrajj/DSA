class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n,-1);
        for(int i=0;i<(n*2)-1;i++){
            while(!st.empty() && nums[st.top()] < nums[i%n]){
                res[st.top()] = nums[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return res;
    }
};