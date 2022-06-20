class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int currRoom = q.front();
            q.pop();
            if(visited[currRoom]) continue;
            visited[currRoom] = 1;
            for(auto &room : rooms[currRoom]){
                if(room==currRoom || visited[room])
                    continue;
                q.push(room);
            }
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==0)
                return false;
        }
        return true;
    }
};