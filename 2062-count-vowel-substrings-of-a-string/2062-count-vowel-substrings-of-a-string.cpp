class Solution {
public:
    int countVowelSubstrings(string word) {
        int n = word.length();
        if(n<5) return 0;
        int count=0;
        set<char> vowel;
        for(int i=0;i<n-4;i++){
            vowel.clear();
            for(int j=i;j<n;j++){
                char c = word[j];
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    vowel.insert(c);
                    if(vowel.size()==5)
                        count++;
                }
                else
                    break;
            }
        }
        return count;
    }
};