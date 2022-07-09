class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int n = buses.size();
        int m = passengers.size();
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        
        unordered_set<int> map;
        
        int load = 0;
        int j=0;
        int last=0;
        for(int i=0;i<n;i++){
            load = 0;
            while(j<m && passengers[j]<=buses[i] && load<capacity){
                map.insert(passengers[j]);
                last = passengers[j];
                load++;
                j++;
            }  
        }
        int finalRes=0;
        if(last==0)
            finalRes = buses[n-1];
        else if(load==capacity)
            finalRes = last;
        else
            finalRes = buses[n-1];
        
        while(finalRes>=0){
            if(map.find(finalRes)==map.end())
                return finalRes;
            finalRes--;
        } 
        return 0;
    }
};