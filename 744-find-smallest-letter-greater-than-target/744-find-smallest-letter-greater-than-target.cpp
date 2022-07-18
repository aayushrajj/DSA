class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low=0,high=n-1;
        char res=NULL;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(letters[mid]<=target)
                low = mid+1;
            else if(letters[mid]>target){
                res = letters[mid];
                high = mid-1;
            }
        }
        
        return res==NULL ? letters[0] : res;
    }
};