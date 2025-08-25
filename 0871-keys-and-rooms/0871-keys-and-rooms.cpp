class Solution {
public:
    void dfs(int node,vector<bool>& vis,unordered_map<int,vector<int>> &adj,vector<vector<int>>& rooms){
        if(vis[node]) return;
        vis[node]=true;
        for(int i:adj[node]){
            if(!vis[i]) dfs(i,vis,adj,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>> adj;
        int n=rooms.size();
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> vis(n,false);
        dfs(0,vis,adj,rooms);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};