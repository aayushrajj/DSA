class Solution {
public:
    
    bool checkPartitioning(string s) {
        int n = s.length();
        int pal[n][n];
        memset(pal,0,sizeof(pal));
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0)
                    pal[i][j]=1;
                else if(g==1 && s[i]==s[j])
                    pal[i][j]=1;
                else{
                    if(s[i]==s[j] && pal[i+1][j-1])
                        pal[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(pal[0][i-1] && pal[i][j-1] && pal[j][n-1])
                    return true;
            }
        }
        return false;
    }
};