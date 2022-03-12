class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int n = startTime.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(queryTime>=startTime[i] && queryTime<=endTime[i])
                count++;
        }
        return count;
    }
};