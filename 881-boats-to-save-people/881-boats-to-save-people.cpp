class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int count=0,sum=0;
        int i=0,j=n-1;
        while(i<=j){
            sum = 0;
            if(i==j)
                sum = people[j];
            else
                sum = people[i]+people[j];
            if(sum<=limit){
                count++;
                j-- , i++;
            }
            else{
                if(people[j]<=limit)
                    count++ , j--;
            }
        }
        return count;
    }
};