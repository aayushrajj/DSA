class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int mismatch = 0;
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='[')
                st.push(s[i]);
            else{
                if(!st.empty())
                    st.pop();
                else
                    mismatch++;
            }
        }
        return (mismatch+1)/2;
    }
};