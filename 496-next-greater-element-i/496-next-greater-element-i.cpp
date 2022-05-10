class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int,int> map;
        stack<int> st;
        vector<int> res;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i])
                st.pop();
            
            if(st.empty())
                map[nums2[i]] = -1;
            else
                map[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        for(auto v : nums1){
            res.push_back(map[v]);
        }
        return res;
    }
};