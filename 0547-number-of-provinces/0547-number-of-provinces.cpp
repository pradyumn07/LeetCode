class Solution {
public:
    void dfs(int &i,unordered_map<int,vector<int>> &adj,vector<vector<int>>& isConnected,vector<bool>& vis){
        if(vis[i]==true) return;
        vis[i]=true;
        for(int node:adj[i]){
            if(!vis[node]){
                dfs(node,adj,isConnected,vis);
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
        int province=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,isConnected,vis);
                province++;
            }
        }
        return province;
    }
};