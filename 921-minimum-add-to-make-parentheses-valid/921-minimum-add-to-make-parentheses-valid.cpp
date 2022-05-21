class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int open = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(s[i]);
            else{
                if(!st.empty())
                    st.pop();
                else
                    open++;
            }
        }
        int total = st.size() + open;
        return total;
    }
};