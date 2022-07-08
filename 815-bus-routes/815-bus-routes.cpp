class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // adjency list  : each bus-stop --> bus1 , bus2 , bus3 ....
        
        unordered_map<int,vector<int>> to_routes;
        for( int bus=0; bus<routes.size(); bus++ ){
            for(auto bus_stop : routes[bus]){
                to_routes[bus_stop].push_back(bus);
            }
        }
        
        queue<pair<int,int>> q;
        q.push({source,0}); // bus-stop , bus-change count
        unordered_set<int> visited;
        visited.insert(source);
        
        while(!q.empty()){
            auto [currStop,busCount] = q.front();
            q.pop();
            
            if(currStop==target)
                return busCount;
            
            for(auto crossingBus : to_routes[currStop]){
                for(auto stop : routes[crossingBus] ){
                    if(visited.find(stop)==visited.end()){
                        visited.insert(stop);
                        q.push({stop,busCount+1});
                    }
                }
                routes[crossingBus].clear();
            }  
        }
        
        return -1;
        
    }
};