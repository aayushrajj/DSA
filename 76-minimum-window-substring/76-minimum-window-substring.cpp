class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        unordered_map<char,int> map2;
        for(auto v : t){
            map2[v]++;
        }
        int matchcount = 0;
        int desiredcount = t.length();
        unordered_map<char,int> map1;
        int i=0,j=0;
        while(true){
            bool flag1 = false;
            bool flag2 = false;
            //acquire
            while(i<s.length() && matchcount<desiredcount){
                map1[s[i]]++;
                if(map1[s[i]]<=map2[s[i]])
                    matchcount++;
                i++;
                flag1 = true;
            }
            
            //collect answer and release
            while(j<i && matchcount==desiredcount){
                string pans = s.substr(j,i-j);
                if(ans.length()==0 || ans.length()>pans.length())
                    ans = pans;
                if(map1[s[j]]==0)
                    map1.erase(s[j]);
                else
                    map1[s[j]]--;
                if(map1[s[j]]<map2[s[j]])
                    matchcount--;
                j++;
                flag2 = true;
            }
            
            if(flag1==false && flag2==false)
                break;
        }
        
        return ans;
    }
};