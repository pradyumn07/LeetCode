class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>& adj,vector<bool>& vis){
        if(vis[node]) return;
        vis[node]=true;
        for(int &v:adj[node]){
            if(!vis[v]){
                dfs(v,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                count++;
            }
        }
        return count;
    }
};