bool mysort(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(),boxTypes.end(),mysort);
        int totalunits = 0;
        for(int i=n-1;i>=0;i--){
            if(boxTypes[i][0]<=truckSize){
                totalunits += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                totalunits += truckSize*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            if(truckSize<=0)
                break;
        }
        
        return totalunits;
    }
};